#include "repository.h"
#include "ambulance.h"
#include "request.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
private:
	Repository<Request> reqs;
	Repository<Ambulance> ambs;
public:
	Controller();
	Controller(Repository<class T1> &repo1, Repository<class T2> &repo2);

	void add_new_req(Request &r);
	void add_new_amb(Ambulance &a);
	void solve_1req();

	void read_ambs_from_file(char *filename);
	void read_reqs_from_file(char *filename);
	
	void write_reqs_to_file(char *filename);
	void write_ambs_to_file(char *filename);

	void display_reqs();
	void display_ambs();

}; 

#endif // !CONTROLLER_H
