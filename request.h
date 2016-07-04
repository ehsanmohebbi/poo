#include <string>
#include<iostream>
using namespace std;

#ifndef REQUEST_H
#define REQUEST_H


class Request {
private:
	char *description;
	int priority;
public:
	Request();
	Request(char *d, int p);
	Request(const Request &r);
	Request &operator =(const Request &r);
	bool operator == (const Request &r);

	char *getDescription();
	int getPriority();
	
	void setDescription(char *d);
	void setPriority(int p);
	
	void displayReq();

	~Request();

	friend ostream &operator<<(ostream &os, const Request&r);
	friend istream &operator>>(istream &is, Request&r);
};

#endif // !REQUEST_H