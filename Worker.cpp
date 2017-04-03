#include "Worker.h"


Worker::Worker():Employee()
{	
	job = "null";
}
ostream & operator <<(ostream & output, Worker &e) {
	Employee &p = e;
	cout << p;
	output << "job:" << e.job << endl;
	cout << "--------------------------" << endl;
	return output;
}
istream & operator >> (istream &input, Worker &e) {
	Employee &p = e;
	cin >> p;
	cout << "job:";
	getline(input, e.job);
	cout << endl;
	return input;
}
void Worker::display() {
	cout << *this;
}

void Worker::set_job(string job)
{
	this->job = job;
}

string Worker::get_job()
{
	return this->job;
}
