#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;
 class  Employee {
private:
	string  num;
	string  name;
	string sex;
	int salary;
	int birth;
	string department;
	int worktime;
	int age;
public:
	Employee();
	virtual void display();
	friend ostream & operator <<(ostream &, Employee &);
	friend istream & operator >> (istream &, Employee &);
	void set_num(string s);
	void set_name(string name);
	void set_sex(string );
	void set_salary(int );
	void set_birthandage(int );
	void set_department(string );
	void set_worktime(int );
	string get_num();
	string get_name();
	string get_sex();
	int get_salary();
	int get_birth();
	string get_department();
	int get_worktime();
	int get_age();

protected:
	int calculate_age();

};




