#include "controller.h"

#ifndef UI_H
#define UI_H

class Console {
private:
	Controller ctrl;
public:
	Console();

	void print_menu();
	void run();
};
#endif