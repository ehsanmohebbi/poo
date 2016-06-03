#include <iostream>
#include "repository.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	cout << "It works!" << endl;

	// testare constructor implicit
	Note_poo np = Note_poo();
	cout << np.toString() << endl;

	// testare constructor de copiere
	Note_poo np2 = Note_poo(np);
	cout << np.toString() << endl;

	//testare constructor cu 3 parametri
	Note_poo np3 = Note_poo(2.1, 3.0, 0.94);
	cout << np3.toString() << endl;

	// testare setter
	cout << "NP4 changed value nta_examen after copyied np3" << endl;
	Note_poo np4 = Note_poo(np3);
	np4.setNotaExamen(100);
	cout << np4.toString() << endl;

	cout << np4 << endl;

	/*
	ofstream f ("Fileout2"); //, ofstream::out);
	f << np4 << endl;
	f << np3 << endl;
	f << np4 << endl;
	*/

	ifstream fin("Fileout");

	cout << " Test citire" << endl;

	while (!fin.eof()) {
		Note_poo np_x;

		fin >> np_x;
		cout << np_x << endl;
	}


	cout << np4 << endl;
	for (int i = 0; i < 3; i++) {
		np4++;
		cout << np4 << endl;
	}

	system("pause");

	return 0;
}