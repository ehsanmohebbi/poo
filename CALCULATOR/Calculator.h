#ifndef CALCULATOR_H
#define CALCULATR_H

#include "complex.h"

class Calculator {
public:
	Calculator();

	int add_naturals(int x, int y);
	int add_multiple_naturals(int vec[], int n);
	Complex add_complex(Complex c1, Complex c2);
};

#endif // CALCULATOR_H