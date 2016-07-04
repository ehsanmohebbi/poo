#include "ambulance.h"
#include <string>
#include <iostream>
using namespace std;

Ambulance::Ambulance() {
	plate = new char[12];
	strcpy(plate, (char*)"12_CL_AMB");
	time = 10;
}

Ambulance::Ambulance(char *p, int t) {
	plate = new char[strlen(p) + 1];
	strcpy(plate, p);
	time = t;
}

Ambulance::Ambulance(const Ambulance &a) {
	plate = new char[strlen(a.plate) + 1]; 
	strcpy(plate,a.plate);
	time = a.time;

}

Ambulance &Ambulance::operator = (const Ambulance &a) {
	if (this != &a) {
		plate = new char[strlen(a.plate) + 1];
		strcpy(plate, a.plate);
		time = a.time;
	}
	return *this;
}

bool Ambulance::operator == (const Ambulance &a) {
	return (strcmp(plate, a.plate) == 0) && (time == a.time);
}

char* Ambulance::getPlate() {
	return plate;
}

int Ambulance::getTime() {
	return time;
}

void Ambulance::setPlate(char *p) {
	plate = new char[strlen(p) + 1];
	strcpy(plate, p);
}

void Ambulance::setTime(int t) {
	time = t;
}

void Ambulance::displayAmb() {
	cout << "Ambulance: " << endl;
	cout << "\t" << "numar de matricolare:  "<<plate << endl;
	cout << "\t" << "Timpul pauzei:  "<<time<< "  min" << endl;
}

ostream &operator<<(ostream &os, const Ambulance &a) {
	os << a.plate << " | " << a.time;

	return os;
}

istream &operator>>(istream &is, Ambulance &a) {
	char buf[20];
	int time_elapsed;

	// read the description
	is >> buf;
	a.setPlate(buf);

	// skip delimiter character: '|'
	is >> buf;

	// read the priority
	is >> time_elapsed;
	a.setTime(time_elapsed);

	return is;

}

Ambulance::~Ambulance() {
	delete plate;
	time = 0;
}
