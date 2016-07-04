#include "user_interface.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

UserInterface::UserInterface() {}

void UserInterface::print_menu() {
	cout << "1. Add 2 natural numbers" << endl;
	cout << "2. Add 2 complex numbers" << endl;
	cout << "3. Add multiple natural numbers" << endl;
	cout << "0. Exit" << endl;
}

bool checkIsNumber(char buf[]) {
	if (buf[0] == '0' && strlen(buf) > 1)
		return false;

	for (int i = 0; i < strlen(buf); i++) {
		if (buf[i] < '0' || buf[i] > '9')
			return false;
	}

	return true;
}

void UserInterface::run() {
	int opt = 1;
	char buf[20];
	int vec[50];
	int x, y, n, rez;

	while (opt != 0) {
		print_menu();

		cin >> opt;
		
		switch (opt) {
		case 1:
			cout << "Enter frist number" << endl;
			cin >> buf;
			if (checkIsNumber(buf) == false)
				throw "Expected number input!";
			x = atoi(buf); // poate genera exceptii daca se introduce altcv decat cifre

			cout << "Enter second number" << endl;
			cin >> buf;
			if (checkIsNumber(buf) == false)
				throw "Expected number input!";
			y = atoi(buf); // poate genera exceptii daca se introduce altcv decat cifre

			cout << "Rezultat: " << calc.add_naturals(x, y) << endl;
			break;

		case 3:
			cout << "Please enter the number of values youw ant to add(n):" << endl;

			cin >> buf;
			if (checkIsNumber(buf) == false)
				throw "Expected number input!";

			n = atoi(buf);

			cout << "Please enter all the numbers" << endl;
			for (int i = 0; i < n; i++) {
				cin >> vec[i];
			}

			rez = calc.add_multiple_naturals(vec, n);
			cout << "Rezultat: " << rez << endl;
			break;

		}
	}
}

