#pragma once

#include <vector>
#include <iostream>
#include <iomanip>

template <class T> class matrix{
private:
	unsigned r_;
	unsigned c_;
	std::vector<std::vector<T>> M_;
public:
	// Constructors
	matrix<T>();
	matrix<T>(unsigned r, unsigned c);
	matrix<T>(const std::vector<std::vector<T>> &M);
	~matrix<T>();
	// Shape-like functions
	unsigned n_rows();
	unsigned n_columns();
	std::vector<unsigned> shape();
	// Access operators
	T& operator()(const unsigned& i, const unsigned& j);
	std::vector<T>& operator()(const unsigned& i);
	//const T& operator()(const unsigned& i, const unsigned& j) const;
	// Matrix-Matrix Arithmetic Operations
	matrix<T> operator+(const matrix<T> &M);
	matrix<T> operator-(const matrix<T> &M);
	matrix<T> operator*(const matrix<T> &M);
	matrix<T> operator^(unsigned k);
	matrix<T>& operator+=(const matrix<T> &M);
	matrix<T>& operator-=(const matrix<T> &M);
	matrix<T>& operator*=(const matrix<T> &M);
	matrix<T> transpose();
	// Matrix-vector arithmetic operations
	matrix<T> operator+(const std::vector<T> &v);
	matrix<T> operator-(const std::vector<T> &v);
	std::vector<T> operator*(const std::vector<T> &v);


	//std::ostream& operator<<(std::ostream& os, matrix<T> &m);
};

