#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include <iostream>

using namespace std;

class Note_poo
{
private:
	float nota_examen;
	float nota_lab;
	float puncte_extra;

public:

	Note_poo();

	Note_poo(const Note_poo &np);

	Note_poo(float ne, float nl, float pe);

	// operatori

	Note_poo &operator= (const Note_poo &np);

	friend ostream & operator<< (ostream &os, Note_poo &np);
	
	friend istream &operator>>(istream &is, Note_poo &np);

	Note_poo &operator++(int x);

	//get
	float getNotaExamen();
	float getNotaLab();
	float getPuncteExtra();

	//set
	void setNotaExamen(float ne);

	void setNotaLab(float nl);
	
	void setPuncteExtra(float pe);

	string toString();

};
#endif