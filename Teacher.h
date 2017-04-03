#pragma once
#include "Employee.h"

class Teacher :
	public Employee
{
public:
	Teacher();
	friend ostream & operator <<(ostream & cout, Teacher &);
	friend istream & operator >> (istream &cin, Teacher &);
	virtual void display();
	void set_faculty(string);
	string get_faculty();
private:
	string faculty;
};
