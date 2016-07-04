#include "request.h"

Request::Request() {
	description = new char[25];
	strcpy(description, (char *)"Work_Accident");
	priority = 9;
}

Request::Request(char *d, int p) {
	if (p < 0 || p > 9)
		throw "Priority must be between [0, 9]";
	description = new char[strlen(d) + 1];
	strcpy(description, d);
	priority = p;
}

Request::Request(const Request &r) {
	description = new char[strlen(r.description) + 1];
	strcpy(description, r.description);
	priority = r.priority;
}

Request &Request::operator = (const Request &r) {
	if (this != &r) {
		description = new char[strlen(r.description) + 1];
		strcpy(description, r.description);
		priority = r.priority;
	}
	return *this;
}

bool Request::operator== (const Request &r) {
	return (strcmp(description, r.description) == 0) && (priority == r.priority);
}

char* Request::getDescription() {

	return description;
}

int Request::getPriority() {

	return priority;
}

void Request::setDescription(char *d) {
	description = new char[strlen(d) + 1];
	strcpy(description, d);
}

void Request::setPriority(int p) {
	if (p < 0 || p > 9)
		throw "Priority must be between [0, 9]";
	priority = p;
}

void Request::displayReq()
{
	cout << "Request: " << endl;
	cout << "\tDescription: " << description << endl;
	cout << "\tPriority: " << priority << endl;
}

Request::~Request() {
	delete description;
	priority = 0;
}

ostream &operator<<(ostream &os, const Request &r) {
	os << r.description << " | " << r.priority ;

	return os;
}

istream &operator>>(istream &is, Request &r) {
	char buf[20];
	int prior;

	// read the description
	is >> buf;
	r.setDescription(buf);

	// skip delimiter character: '|'
	is >> buf;

	// read the priority
	is >> prior;
	r.setPriority(prior);

	return is;

}