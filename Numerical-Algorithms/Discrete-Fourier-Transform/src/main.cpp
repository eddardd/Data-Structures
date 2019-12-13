#include "DFT.h"

int main() {
	std::vector<double> x = { 8, 4, 8, 0 };
	DFT dft(x);
	dft.computeTransform();
	std::cout << dft << std::endl;
}
