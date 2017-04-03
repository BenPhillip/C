#include "Employee.h"



Employee::Employee() {
	num = "NULL";
	name = "NULL";
	sex = "null";
	salary = 0;
	birth = 0;
	department = "NULL";
	worktime = NULL;
	age = NULL;
}

void Employee::display()
{	
	cout << *this;
}

void Employee::set_num(string num)
{
	this->num = num;
}

void Employee::set_name(string name)
{
	this->name = name;
}

void Employee::set_sex(string sex)
{
	this->sex = sex;

}

void Employee::set_salary(int salary)
{
	this->salary = salary;
}

void Employee::set_birthandage(int birth)
{
	this->birth = birth;
	this->age=calculate_age();
}

void Employee::set_department(string department)
{
	this->department=department;
}

void Employee::set_worktime(int time)
{
	this->worktime = time;
}

string Employee::get_num()
{
	return this->num;
}

string Employee::get_name()
{
	return this->name;
}

string Employee::get_sex()
{
	return this->sex;
}

int Employee::get_salary()
{
	return this->salary;
}

int Employee::get_birth()
{
	return this->birth;
}

string Employee::get_department()
{
	return this->department;
}

int Employee::get_worktime()
{
	return this->worktime;
}

int Employee::get_age()
{
	return this->age;
}

int Employee::calculate_age() {
	SYSTEMTIME time;
	GetLocalTime(&time);
	return time.wYear - birth;
}


ostream & operator<<(ostream & cout, Employee &e)
{
	cout << "--------------------------" << endl;
	cout << "num:" << e.num << endl;
	cout << "name:" << e.name << endl;
	cout << "sex:" << e.sex << endl;
	cout << "birth:" << e.birth << endl;
	cout << "age:" << e.calculate_age() << endl;
	cout << "department:" << e.department << endl;
	cout << "worktime:" << e.worktime << endl;
	cout << "salary:" << e.salary << endl;
		return cout;
}

istream & operator >> (istream & cin, Employee &e)
{
	cout << "input num:";
	getline(cin,e.num);
	cout << "input name:"; 
	getline(cin, e.name);
	cout << "input sex:";
	getline(cin, e.sex);
	cout << "input birth(year):";
	cin >> e.birth;
	getchar();
	cout << "input department:";
	getline(cin, e.department);
	cout << "worktime:";
	cin >> e.worktime;
	getchar();
	cout << "salary:";
	cin >> e.salary;
	getchar();
	return cin;
}
