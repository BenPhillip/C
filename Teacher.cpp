#include "Teacher.h"


Teacher::Teacher():Employee()
{
	faculty = "null";
}
ostream & operator <<(ostream & output, Teacher &e) {
	Employee &p = e;
	cout <<p;
	output << "faculty:" << e.faculty << endl;
	cout << "--------------------------" << endl;
	return output;
}
istream & operator >> (istream &input, Teacher &e) {
	Employee &p = e;
	cin >> p;
	cout << "faculty:";
	getline(input, e.faculty);
	cout << endl;
	return input;
}
void Teacher::display(){
	cout << *this;
}


void Teacher::set_faculty(string faculty)
{
	this->faculty = faculty;
}

string Teacher::get_faculty()
{
	return this->faculty;
}
