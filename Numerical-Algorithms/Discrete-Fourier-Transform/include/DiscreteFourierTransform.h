#pragma once

#include "matrix.h"
#include <complex>
#include <string>

class DiscreteFourierTransform {
private:
	unsigned N_;                     // Number of samples
	std::vector<double> x_;          // Vector with samples
	std::vector<double> X_real_;     // Fourier transform real part
	std::vector<double> X_imag_;     // Fourier transform imaginary part
	matrix<std::complex<double>> W_; // Transformation matrix
	matrix<double> Wreal_;			 // Transformation matrix real part
	matrix<double> Wimag_;			 // Transformation matrix imag part
public:
	DiscreteFourierTransform();
	DiscreteFourierTransform(std::vector<double> x);
	DiscreteFourierTransform(const DiscreteFourierTransform& dft);
	~DiscreteFourierTransform();
	friend std::ostream& operator<<(std::ostream& os, DiscreteFourierTransform& dft);
	void computeTransform();
	std::vector<double> getx();
	std::vector<std::complex<double>> getX();
};