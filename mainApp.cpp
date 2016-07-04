#include "ambulance.h"
#include "request.h"
#include <iostream>
#include "repository.h"
#include "controller.h"
#include "UI.h"

using namespace std;


void testAmbu_Req(){

	Ambulance a1, a2, a;
	Request r1, r2, r;


	a.displayAmb();
	r.displayReq();

	a1 = Ambulance((char *)"B_21_Amb", 10);
	a2 = a1;

	a1.displayAmb();
	a2.displayAmb();

	r1 = Request((char *)"car_accedent", 5);
	r2 = r1;

	r1.displayReq();
	r2.displayReq();

	if (r1 == r2)
		cout << "Request op == works!" << endl << endl;
	else
		cout << "Request op == not working!" << endl << endl;

	if (a1 == a2)
		cout << "ambulance op == works!" << endl;
	else
		cout << "ambulance op == not working!" << endl;

}

void test_repo() {
	Repository <Request> repo;
	Request r1;
	Request r2 = Request((char *)"car_accident", 5);
	Request r3 = Request((char *)"fire", 3);

	repo.adauga(r1);
	repo.adauga(r2);
	repo.adauga(r3);

	repo.display_repo();
	cout << repo.index_of(r2) << endl;
	cout << repo.elem_at(2) << endl;

	cout << "NR elems: " << repo.get_nr_elem() << endl;

	repo.write_to_file("requests.out");

}


void test_controller() {
	Controller control;

	Ambulance a1, a2;
	a1 = Ambulance((char *)"A1", 12);
	a2 = Ambulance((char *)"A2", 4);

	Request r1, r2;
	r1 = Request((char *)"R1", 0);
	r2 = Request((char *)"R2", 5);

	control.add_new_amb(Ambulance());
	control.add_new_req(Request());
	control.add_new_amb(a2);
	control.add_new_amb(a1);

	control.add_new_req(r1);
	control.add_new_req(r2);

	control.display_ambs();
	control.display_reqs();

	control.solve_1req();

	Repository<Ambulance> *repo = new Repository<Ambulance>();
}


class A {
public:
	A& operator=(const A &a) {
		cout << "opA" << endl;

		return *this;
	}

	A() { cout << "constrA" << endl; }
	~A() { cout << "destructorA" << endl; }


};

A fc() {
	A al;

	return al;
}

int main() {
	Console cons;
	cons.run();

	system("pause");

	return 0;
}