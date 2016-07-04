#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef REPO_H
#define REPO_H

template <class T, int dim = 100> class Repository 
{
private:
	T vec[dim];
	int nr_elem;
public:
	Repository();
	Repository(T* vec, int l);
	Repository(const Repository<T, dim> &t);			
	Repository &operator = (const Repository<T, dim> &t);
	
	int get_nr_elem();
	void set_nr_elem(int nr);
	T* get_all_elems();

	T elem_at(int poz);
	int index_of(T e);
	void adauga(T e);						
	void sterge(T e);							
	bool apartine(T e);							
	bool inclus(Repository r2);				
	bool operator == (Repository r2);			
	void load_from_file(char *s1);				
	void write_to_file(char *s2);				
	void display_repo();

	~Repository();
};

template <class T, int dim> Repository<T, dim>::Repository() { nr_elem = 0; }
template <class T, int dim> Repository<T, dim>::Repository(T *vec, int l) {
	for (int i = 0; i < l; ++i)
		adauga(vec[i]);
	nr_elem = l;
}

template <class T, int dim> Repository<T, dim>::Repository(const Repository<T, dim> &t) {
	for (int i = 0; i < t.nr_elem; ++i)
		adauga(t.vec[i]);
	nr_elem = t.nr_elem;
}

template<class T, int dim>Repository<T, dim> &Repository<T, dim>::operator = (const Repository<T, dim> &t) {
	if (this != &t) {
		nr_elem = t.nr_elem;
		for (int i = 0; i < t.nr_elem; ++i)
			this->adauga(t.vec[i]);
		return *this;
	}
}

template <class T, int dim> int Repository<T, dim>::get_nr_elem() { return nr_elem; }

template <class T, int dim> void Repository<T, dim>::set_nr_elem(int nr) { nr_elem = nr; }

template <class T, int dim> T* Repository<T, dim>::get_all_elems() { return vec; }

template <class T, int dim> T Repository<T, dim>::elem_at(int poz)
{
	if (poz < 0 || poz > nr_elem - 1) {
			throw "Pozitie nevalida!";
	}
	else
		return vec[poz];
}

template <class T, int dim> void Repository<T, dim>::adauga(T e) {
	if (!apartine(e)) {
		if (nr_elem < dim)
		{
			vec[nr_elem] = e;
			nr_elem++;
		}
		else
			throw ("vecul este plin!");
	}
}

template <class T, int dim> void Repository<T, dim>::sterge(T e) {
	int poz = index_of(e);

	if (poz > -1)
	{
		for (int i = poz; i < nr_elem - 1; i++)
			v[i] = v[i + 1];

		nr_elem--;
	}
}

template <class T, int dim> int Repository<T, dim>::index_of(T e) {
	for (int i = 0; i < nr_elem; ++i)
		if (vec[i] == e)
			return i;
	return -1;
}

template <class T, int dim>  bool Repository<T, dim>::apartine(T e) {
	if (index_of(e) > -1)
		return true;
	return false;
}

template <class T, int dim>bool Repository<T, dim>::inclus(Repository<T, dim> r2) {
	for (int i = 0; i < nr_elem; i++)
		if (r2.apartine(vec[i]) == false)
			return false;
	return true;
}

template <class T, int dim> bool Repository<T, dim>::operator ==(Repository<T, dim> r2) {
	return (this->inclus(r2) && r2.inclus(*this));
}

template <class T, int dim> void Repository<T, dim>::load_from_file(char *s1) {
	ifstream fin(s1);
	T t;
	int n = 0;
	fin >> n; //n = first line contains the number of elems in file

	for (int i = 0; i < n; ++i)
	{
		fin >> t;
		//cout << "read from file: " << t << endl;
		adauga(t);
	}

	fin.close();
}
template <class T, int dim> void Repository<T, dim>::write_to_file(char *s2) {
	if (nr_elem <= 0)
		throw("vectorul este gol!");

	load_from_file(s2);//if file not empty, copy content into current repo then overwrite it.

	ofstream fout(s2);

	fout << nr_elem << endl;

	for (int i = 0; i < nr_elem; ++i)
		fout << vec[i] << endl;
	fout.close();
}
template <class T, int dim> void Repository<T, dim>::display_repo() {

	for (int i = 0; i < nr_elem; ++i)
		cout << vec[i] << endl;
}
template <class T, int dim> Repository<T, dim>::~Repository() { nr_elem = -1; }

#endif // !REPO_H


