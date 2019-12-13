#include "DiscreteFourierTransform.h"


DiscreteFourierTransform::DiscreteFourierTransform() : N_(0) {};

DiscreteFourierTransform::DiscreteFourierTransform(std::vector<double> x) : N_(x.size()), x_(x) {};

DiscreteFourierTransform::DiscreteFourierTransform(const DiscreteFourierTransform& dft) : N_(dft.N_), x_(dft.x_) {};

DiscreteFourierTransform::~DiscreteFourierTransform() {
	this->N_ = 0;
	this->x_.clear();
	this->X_real_.clear();
	this->X_imag_.clear();
}

std::ostream& operator<<(std::ostream& os, DiscreteFourierTransform& dft) {
	for (unsigned i = 0; i < dft.N_; i++) {
		os << std::to_string(dft.X_real_[i]) + " + i" + std::to_string(dft.X_imag_[i]) << ' ';
	}
	return os;
}

void DiscreteFourierTransform::computeTransform() {
	this->W_ = matrix<std::complex<double>>(this->N_, this->N_);
	this->Wreal_ = matrix<double>(this->N_, this->N_);
	this->Wimag_ = matrix<double>(this->N_, this->N_);
	this->X_real_ = std::vector<double>(this->N_);
	this->X_imag_ = std::vector<double>(this->N_);
	unsigned j, k;
	const std::complex<double> i(0, 1);
	const double pi = std::atan(1) * 4;
	for (j = 0; j < this->N_; j++) {
		for (k = 0; k < this->N_; k++) {
			this->W_(j, k) = std::exp(i * (double)2 * pi * (double)j * (double)k / (double)this->N_);
			this->Wreal_(j, k) = this->W_(j, k).real();
			this->Wimag_(j, k) = this->W_(j, k).imag();
		}
	}
	this->X_real_ = this->Wreal_ * this->x_;
	this->X_imag_ = this->Wimag_ * this->x_;
}

std::vector<double> DiscreteFourierTransform::getx() {
	return this->x_;

}

std::vector<std::complex<double>> DiscreteFourierTransform::getX() {
	std::vector<std::complex<double>> X;
	for (int j = 0; j < this->N_; j++) {
		X[j] = (this->X_real_[j], this->X_imag_[j]);
	}
	return X;
}
