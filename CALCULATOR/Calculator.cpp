#include "Calculator.h"

Calculator::Calculator() {}

int Calculator::add_naturals(int x, int y) {
	return x + y;
}


int Calculator::add_multiple_naturals(int vec[], int n) {
	int sum = 0;

	for (int i = 0l; i < n; i++) {
		sum += vec[i];
	}

	return sum;
}
