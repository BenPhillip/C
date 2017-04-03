#pragma once
 People people;
Teacher t1;
Teacher t2;
Teacher t3;
Teacher t4;
Teacher t5;
Worker w1;
Worker w2;
Worker w3;
Worker w4;
Worker w5;
Teacher t[5]; 
Worker w[5]; 

void add_employee() {
	People *p = &people;
	int i;
	cout << "\t\t请选择要添加的类型" << endl;
	cout << "\t\t 1.教师" << endl;
	cout << "\t\t 2.工人" << endl;
	cin >> i; getchar();
	if (i == 1) {
		People *q = new People();
		Teacher *t = new Teacher();
		cin >> *t;
		q->flage = TRUE;
		q->next = p->next;
		q->t = t;
		p->next = q;
	}
	else if (i == 2) {
		People *q = new People();
		Worker *w = new Worker();
		cin >> *w;
		q->flage = FALSE;
		q->next = p->next;
		q->w = w;
		p->next = q;
	}
	else add_employee();
}

void delete_employee() {
	cout << "输入要删除职员的编号：";
	string num1;
	getline(cin, num1);
	People *p = &people;
	for (People *q = p->next; q != nullptr; p = p->next, q = q->next) {
		if (q->flage) {
			if (q->t->get_num ()== num1)
			{
				p->next = q->next;
				delete q;  
				break;
			}
		}
		else {
			if (q->w->get_num() == num1) {
				p->next = q->next;
				delete q;
				break;
			}

		}

	}

}
void avg_age() {
	People *p = people.next;
	int count_t = 0, count_w = 0;
	int sum_age_t = 0, sum_age_w = 0;
	while (p) {
		if (p->flage) {
			sum_age_t +=( p->t->get_age());
			count_t++;
			
		}
		else {
			sum_age_w += w->get_age();
			count_w++;
		}
		p = p->next;
	}
	cout << "所有的教师平均年龄：" <<(sum_age_t / count_t) << endl;
	cout << "所有的工人平均年龄:" <<(sum_age_w / count_w )<< endl;
}
void search_name() {
	string name;
	People *p = people.next;
	cout << "请输入要检索的职工的姓名" << endl;
	getline(cin, name);
	while (p) {
		if (p->flage) {
			if (p->t->get_name() == name) cout <<"教师信息"<<endl<< *(p->t)<<endl;
		}
		else
			if (p->w->get_name() == name) cout <<"工人信息"<<endl<< *(p->w)<<endl;
		p=p->next;
	}
}
void faculty_teacher() {
	int i;
	People *p = people.next;
	cout << "\t\t1.数理系" << endl;
	cout << "\t\t2.机建系" << endl;
	cout << "\t\t3.其他系" << endl;
	cout << "输入要查询的系:"<<endl;
	cin >> i;
	getchar();
	switch (i) {
	case 1:	
		while (p) {
		if(p->flage == TRUE)
			if (p->t->get_faculty()== "数理系")
				cout << *(p->t) << endl;
		p=p->next;
	}
		break;
	case 2:
		while (p) {
			if(p->flage == TRUE)
				if (p->t->get_faculty() == "机建系")
					cout << *(p->t) << endl;
			p = p->next;
		}
		break;
	default:
		while (p) {
			if(p->flage == TRUE)
				if (!(p->t->get_faculty() == "数理系"|| p->t->get_faculty() == "机建系") )
					cout << *(p->t) << endl;
			p = p->next;
		}
		break;
	}

	
}
void print_employee() {
	People *p = people.next;
	while (p) {
		if (p->flage) 
			cout << *(p->t);
		else cout << *(p->w);
		p=p->next;
	}
}

void start() {
	t1.set_num("10086");
	t1.set_name("赵明明");
	t1.set_sex("男");
	t1.set_salary(8000);
	t1.set_birthandage(1994);
	t1.set_department("南湖学院");
	t1.set_worktime(20150621);
	t1.set_faculty("数理系");


	t2.set_num("10087");
	t2.set_name("钱安安");
	t2.set_sex("男");
	t2.set_salary(10000);
	t2.set_birthandage(1987);
	t2.set_department("南湖学院");
	t2.set_worktime(20140508);
	t2.set_faculty("商学系");


	t3.set_num("10088");
	t3.set_name("孙晓姗");
	t3.set_sex("女");
	t3.set_salary(9000);
	t3.set_birthandage(1990);
	t3.set_department("南湖学院");
	t3.set_worktime(20150311);
	t3.set_faculty("商学系");

	
	t4.set_num("10089");
	t4.set_name("李 斯");
	t4.set_sex("男");
	t4.set_salary(7000);
	t4.set_birthandage(1992);
	t4.set_department("南湖学院");
	t4.set_worktime(20150701);
	t4.set_faculty("机建系");


	t5.set_num("10090");
	t5.set_name("本杰明");
	t5.set_sex("男");
	t5.set_salary(8000);
	t5.set_birthandage(1995);
	t5.set_department("南湖学院");
	t5.set_worktime(20150702);
	t5.set_faculty("数理系");

	w1.set_num("10065");
	w1.set_name("林 海");
	w1.set_sex("男");
	w1.set_salary(10000);
	w1.set_birthandage(1996);
	w1.set_department("嘉兴学院");
	w1.set_worktime(20150702);
	w1.set_job("工程师");


	w2.set_num("10066");
	w2.set_name("周武光");
	w2.set_sex("男");
	w2.set_salary(6000);
	w2.set_birthandage(1994);
	w2.set_department("嘉兴学院");
	w2.set_worktime(20140308);
	w2.set_job("保安");


	w3.set_num("10067");
	w3.set_name("吴海丽");
	w3.set_sex("女");
	w3.set_salary(8000);
	w3.set_birthandage(1990);
	w3.set_department("南湖学院");
	w3.set_worktime(20150409);
	w3.set_job("图书管理员");


	w4.set_num("10069");
	w4.set_name("王 磊");
	w4.set_sex("男");
	w4.set_salary(9000);
	w4.set_birthandage(1988);
	w4.set_department("嘉兴学院");
	w4.set_worktime(20150105);
	w4.set_job("系统管理员");


	w5.set_num("10096");
	w5.set_name("王 菲");
	w5.set_sex("男");
	w5.set_salary(9000);
	w5.set_birthandage(1988);
	w5.set_department("嘉兴学院");
	w5.set_worktime(20150105);
	w5.set_job("系统管理员");

	People *p = &people;

	for (int i = 0; i < 10; i++, p = p->next) {
		if (i < 5) {
			p->next = new People();
			p->next->flage = TRUE;
			p->next->t = &t[i];
			//cout << *(p->next->t);

		}
		else
		{
			p->next = new People();
			p->next->flage = FALSE;
			p->next->w = &w[i - 5];
		}

	}
	t[0] = t1;
	t[1] = t2;
	t[2] = t3;
	t[3] = t4;
	t[4] = t5;
	w[0] = w1;
	w[1] = w2;
	w[2] = w3;
	w[3] = w4;
	w[4] = w5;
}