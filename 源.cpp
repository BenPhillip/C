#include<iostream>
#include<string>
#include"Employee.h"
#include"menu.h"
#include"Teacher.h"
#include"People.h"
#include"Worker.h"
#include"ways.h"
using namespace std;

void main() {
		int choose;
		start();
		while (1) {
			cout_menu();
			cin >> choose;
			getchar();
			switch (choose) {
			case 1:add_employee(); break;
			case 2:delete_employee(); break;
			case 3:avg_age(); break;
			case 4:search_name(); break;
			case 5:faculty_teacher(); break;
			case 6:print_employee(); break;
			case 7:cout << "program is over"; exit(0);
			default:cout << "please choose true num!" << endl; break;
			}

		}
	}



