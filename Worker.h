#pragma once
#include "Employee.h"
class Worker :
	public Employee
{
public:
	Worker();
	friend ostream & operator <<(ostream & , Worker &);
	friend istream & operator >> (istream &, Worker &);
	virtual void display();
	void set_job(string job);
	string get_job();
private:
	string job;
};

