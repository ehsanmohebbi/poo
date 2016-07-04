#ifndef UINT_H
#define UINT_H

#include "Calculator.h"

class UserInterface {
private:
	Calculator calc;
public:
	UserInterface();

	void print_menu();
	void run();
};

#endif // UI_H