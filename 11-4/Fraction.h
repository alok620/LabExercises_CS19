#ifndef Fraction__H
#define Fraction__H

#include <iostream>


class Fraction {
	
private:
	int numerator;
	int denominator;
	int findCommonDivisor(int num1, int num2);
public:
	void setNumerator(int newNumerator) {
		numerator = newNumerator;
	}
	void setDenominator(int newDenominator) {
		denominator = newDenominator;
	}
	double getAsDouble();
	void outputLowestTerms();
	Fraction() {
		numerator = 3;
		denominator = 5;
	}
	Fraction(int newNumerator, int newDenominator) {
		numerator = newNumerator;
		denominator = newDenominator;
	}

};

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



#endif