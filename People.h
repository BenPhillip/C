#pragma once
#include"Employee.h"
#include"Teacher.h"
#include"Worker.h"
class People
{
public:
	People();
	People *next;
	Teacher *t;
	Worker *w;
	bool flage;
};

