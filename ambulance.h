#include <iostream>
using namespace std;

#ifndef AMBULANCE_H
#define AMBULANCE_H

class Ambulance {
private:
	char *plate;
	int time;
public:
	Ambulance();
	Ambulance(char *p, int t);
	Ambulance(const Ambulance &a);
	Ambulance &operator = (const Ambulance &a);
	bool operator ==(const Ambulance &a);

	//get
	char *getPlate();
	int getTime();

	//set
	void setPlate(char *p);
	void setTime(int t);

	void displayAmb();
	
	~Ambulance();

	friend ostream &operator<<(ostream &os, const Ambulance &a);
	friend istream &operator>>(istream &is, Ambulance &a);

};

#endif // !AMBULANCE_H

