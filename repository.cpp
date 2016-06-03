#include "repository.h"
#include <sstream>
#include <stdlib.h>

using namespace std;

Note_poo::Note_poo()
{
	nota_examen = 5;
	nota_lab = 0;
	puncte_extra = 0;
}

Note_poo::Note_poo(const Note_poo &np)
{

	nota_examen = np.nota_examen;
	nota_lab = np.nota_lab;
	puncte_extra = np.puncte_extra;
}

Note_poo::Note_poo(float ne, float nl, float pe)
{
	nota_examen = ne;
	nota_lab = nl;
	puncte_extra = pe;
}

//operators

Note_poo& Note_poo::operator= (const Note_poo &np)
{
	if (this != &np) {
		nota_examen = np.nota_examen;
		nota_lab = np.nota_lab;
		puncte_extra = np.puncte_extra;
	}

	return *this;
}

Note_poo & Note_poo::operator++(int x) {
	return Note_poo(nota_examen, nota_lab, puncte_extra + 1);

}

ostream & operator<< (ostream &os, Note_poo &np) {
	os << np.getNotaExamen()<< " | ";
	os << np.getNotaLab() << " | ";
	os << np.getPuncteExtra() << " | ";

	return os;
}

istream &operator>>(istream &is, Note_poo &np)
{
	char numar_buf[10];
	char skip_buf[10];

	is >> numar_buf;
	np.setNotaExamen(atof(numar_buf));
	is >> skip_buf;

	is >> numar_buf;
	np.setNotaLab(atof(numar_buf));
	is >> skip_buf;
	
	is >> numar_buf;
	np.setPuncteExtra(atof(numar_buf));
	is >> skip_buf;
	
	return is;
}


//getters

float Note_poo::getNotaExamen() {
	return nota_examen;
}

float Note_poo::getNotaLab() {
	return nota_lab;
}


float Note_poo::getPuncteExtra() {
	return puncte_extra;
}

void Note_poo::setNotaExamen(float ne) {
	nota_examen = ne;
}

void Note_poo::setNotaLab(float nl) {
	nota_lab = nl;
}

void Note_poo::setPuncteExtra(float pe) {
	puncte_extra = pe;
}

string Note_poo::toString() {
	stringstream s;

	s << "nota examen: " << nota_examen << endl; 
	s << "nota lab: " << nota_lab << endl;
	s << "puncte extra: " << puncte_extra << endl;

	return s.str();
}

