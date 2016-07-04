#include "controller.h"

Controller::Controller() {

}

void Controller::add_new_req(Request &r) {
	reqs.adauga(r);
}

void Controller::add_new_amb(Ambulance &a) {
	ambs.adauga(a);
}

void Controller::solve_1req() {
	Ambulance best_ambulance;
	Ambulance *v_ambs = ambs.get_all_elems();

	for (int i = 0; i < ambs.get_nr_elem(); i++) {
		if (best_ambulance.getTime() < v_ambs[i].getTime()) {
			best_ambulance = v_ambs[i];
		}
	}

	Request most_prior_req;
	Request *v_reqs = reqs.get_all_elems();

	for (int i = 0; i < reqs.get_nr_elem(); i++) {
		if (most_prior_req.getPriority() > v_reqs[i].getPriority())
			most_prior_req = v_reqs[i];
	}

	cout << "Next: " << most_prior_req << " GETS AMB " << best_ambulance << endl;
}

void Controller::display_reqs() {
	reqs.display_repo();
}


void Controller::display_ambs() {
	ambs.display_repo();
}


void Controller::read_reqs_from_file(char *filename) {
	reqs.load_from_file(filename);
}


void Controller::read_ambs_from_file(char *filename) {
	ambs.load_from_file(filename);
}

void Controller::write_reqs_to_file(char *filename) {
	reqs.write_to_file(filename);
}

void Controller::write_ambs_to_file(char *filename) {
	ambs.write_to_file(filename);
}
