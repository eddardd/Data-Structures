#include "matrix.h"

// Constructors
template <class T>
matrix<T>::matrix() {
	this->c_ = 0;
	this->r_ = 0;
}

template <class T>
matrix<T>::matrix(unsigned r, unsigned c) {
	std::vector<std::vector<T>> M(r, std::vector<T>(c));
	this->c_ = c;
	this->r_ = r;
	this->M_ = M;
};

template <class T>
matrix<T>::matrix(const std::vector<std::vector<T>> &M) {
	this->M_ = M;
	this->c_ = M.n_columns();
	this->r_ = M.n_rows();
};

template <class T>
matrix<T>::~matrix() {
	unsigned i;
	for (i = 0; i < this->n_rows(); i++) {
		this->M_[i].clear();
	}
	this->M_.clear();
}

// Shape-like functions
template <class T>
unsigned matrix<T>::n_rows() {
	return this->r_;
}

template <class T>
unsigned matrix<T>::n_columns() {
	return this->c_;
}

template <class T>
std::vector<unsigned> matrix<T>::shape() {
	std::vector<unsigned> s(this->r_, this->c_);
	return s;
}

// Access operators
template <class T>
T& matrix<T>::operator()(const unsigned& i, const unsigned& j) {
	return this->M_[i][j];
}

template <class T>
std::vector<T>& matrix<T>::operator()(const unsigned& i) {
	std::vector<T> row(this->c_);
	for (unsigned j = 0; j < this->c_; j++) {
		row[j] = this->M_[i][j];
	}
	return row;
}

// Matrix-Matrix Arithmetic Operations
template <class T>
matrix<T> matrix<T>::operator+(const matrix<T> &M) {
	unsigned i, j;
	matrix<T> result(M.r_, M.c_);
	for (i = 0; i < M.r_; i++) {
		for (i = 0; i < M.c_; j++) {
			result(i, j) = this->M_[i][j] + M(i, j);
		}
	}
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T> &M) {
	unsigned i, j;
	matrix<T> result(M.r_, M.c_);
	for (i = 0; i < M.r_; i++) {
		for (i = 0; i < M.c_; j++) {
			result(i, j) = this->M_[i][j] - M(i, j);
		}
	}
}

template <class T>
matrix<T> matrix<T>::operator*(const matrix<T> &M) {
	unsigned i, j, k;
	matrix<T> result(this->r_, M.c_);
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < M.c_; j++) {
			result(i, j) = 0;
			for (k = 0; k < M.r_; k++) {
				result(i, j) += this->M_[i][k] * M(k, j);
			}
		}
	}
}

template <class T>
matrix<T> matrix<T>::operator^(unsigned k) {
	matrix<T> M(this->n_rows(), this->n_columns());
	M = this->M_;
	for (unsigned i = 1; i < k; i++) {
		M *= this->M_;
	}
	return M;
}

template <class T>
matrix<T>& matrix<T>::operator+=(const matrix<T> &M) {
	unsigned i, j;
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < this->c_; j++) {
			this->M_[i][j] += M(i, j);
		}
	}
	return *this;
}
template <class T>
matrix<T>& matrix<T>::operator-=(const matrix<T> &M) {
	unsigned i, j;
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < this->c_; j++) {
			this->M_[i][j] -= M(i, j);
		}
	}
	return *this;
}

template <class T>
matrix<T>& matrix<T>::operator*=(const matrix<T> &M) {
	matrix<T> result = (*this) * M;
	(*this) = result;
	return *this;
}

template <class T>
matrix<T> matrix<T>::transpose() {
	unsigned i, j;
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < this->c_; j++) {
			this->M_[i][j] = this->M_[j][i];
		}
	}
}

// Matrix-vector arithmetic operations
template <class T>
matrix<T> matrix<T>::operator+(const std::vector<T> &v) {
	unsigned i, j;
	matrix<T> result(this->r_, this->c_);
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < this->c_; j++) {
			result(i, j) = this->M_[i][j] + v[i];
		}
	}
}
template <class T>
matrix<T> matrix<T>::operator-(const std::vector<T> &v) {
	unsigned i, j;
	matrix<T> result(this->r_, this->c_);
	for (i = 0; i < this->r_; i++) {
		for (j = 0; j < this->c_; j++) {
			result(i, j) = this->M_[i][j] - v[i];
		}
	}
}
template <class T>
std::vector<T> matrix<T>::operator*(const std::vector<T> &v) {
	std::vector<T> result(this->r_);
	for (unsigned i = 0; i < this->r_; i++) {
		result[i] = 0;
		for (unsigned j = 0; j < this->c_; j++) {
			result[i] += this->M_[i][j] * v[j];
		}
	}
	return result;
}

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T> &m) {
	for (unsigned i = 0; i < m.n_rows(); i++) {
		for (unsigned j = 0; j < m.n_columns(); j++) {
			os << std::setw(20) << std::right << m(i, j) << " ";
		}
		os << std::endl;
	}
	return os;
}

