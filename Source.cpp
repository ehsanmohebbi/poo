#include "controller.h"

#ifndef UI_H
#define UI_H

class Console {
private:
	Controller ctrl;
public:
	Console();
	void adauga();
	void vinde();
	//void afisare_disp();
	//void afisare_pline();
	void print_menu();
	void run();
};
#endif