#include <iostream>
#include "Fraction.h"

using std::cout;
using std::endl;

double Fraction::getAsDouble() {
	return static_cast<double>(numerator) / denominator;
}

int Fraction::findCommonDivisor(int num1, int num2) {
	int remainder;
	while ((num1 % num2) > 0) {
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;
	}
	return num2;
}

void Fraction::outputLowestTerms() {
	int gcd;
	gcd = findCommonDivisor(numerator, denominator);
	std::cout << (numerator / gcd) << "/"
		<< (denominator / gcd) << std::endl;
}