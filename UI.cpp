#include "UI.h"
//#include "controller.h"

void Console::print_menu() {
	cout << "Options:" << endl;
	cout << "1. Display Requests" << endl;
	cout << "2. Display Ambulances" << endl;
	cout << "3. Add new request" << endl;
	cout << "4. Add new ambulance" << endl;
	cout << "5. Solve 1 (first priority) request" << endl;
	cout << "6. Read ambs from file" << endl;
	cout << "7. Read reqs from file" << endl;
	cout << "8. Save ambs to file" << endl;
	cout << "9. Save reqs to file" << endl;
	cout << "0. Exit" << endl;
}

void Console::run() {
	int op = 1;
	char buf[20];
	int x;

	while (op != 0) {
		cin >> op;

		switch (op) {
			case 1:
				ctrl.display_reqs();
				break;
			case 2:
				ctrl.display_ambs();
				break;
			case 3: {
				Request r;
				cout << "Introduce new request" << endl;
				cout << "Details(one word or connected words with '_'):" << endl;
				cin >> buf;
				cout << "Request priority(0 - 9, 0 the highest priority)" << endl;
				cin >> x;

				r.setDescription(buf);
				r.setPriority(x);
				ctrl.add_new_req(r);
				break;
			}
			case 4: {
				Ambulance a;
				cout << "Introduce new ambulance" << endl;
				cout << "Plate:" << endl;
				cin >> buf;
				cout << "Elapsed time from the last intervention (int - minutes):" << endl;
				cin >> x;

				a.setPlate(buf);
				a.setTime(x);
				ctrl.add_new_amb(a);
				break;
			}
			case 5:{
				ctrl.solve_1req();
				break;
			}
			case 6: {
						cout << "Enter filename:" << endl;
						cin >> buf;
						ctrl.read_ambs_from_file(buf);
						break;
			}
			case 7: {
						cout << "Enter filename:" << endl;
						cin >> buf;
						ctrl.read_reqs_from_file(buf);
						break;
			}
			case 8: {
						cout << "Enter filename:" << endl;
						cin >> buf;
						ctrl.write_ambs_to_file(buf);
						break;
			}
			case 9: {
						cout << "Enter filename:" << endl;
						cin >> buf;
						ctrl.write_reqs_to_file(buf);
						break;
			}
		
		}

	}
}

