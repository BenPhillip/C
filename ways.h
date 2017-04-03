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
	cout << "\t\t��ѡ��Ҫ��ӵ�����" << endl;
	cout << "\t\t 1.��ʦ" << endl;
	cout << "\t\t 2.����" << endl;
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
	cout << "����Ҫɾ��ְԱ�ı�ţ�";
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
	cout << "���еĽ�ʦƽ�����䣺" <<(sum_age_t / count_t) << endl;
	cout << "���еĹ���ƽ������:" <<(sum_age_w / count_w )<< endl;
}
void search_name() {
	string name;
	People *p = people.next;
	cout << "������Ҫ������ְ��������" << endl;
	getline(cin, name);
	while (p) {
		if (p->flage) {
			if (p->t->get_name() == name) cout <<"��ʦ��Ϣ"<<endl<< *(p->t)<<endl;
		}
		else
			if (p->w->get_name() == name) cout <<"������Ϣ"<<endl<< *(p->w)<<endl;
		p=p->next;
	}
}
void faculty_teacher() {
	int i;
	People *p = people.next;
	cout << "\t\t1.����ϵ" << endl;
	cout << "\t\t2.����ϵ" << endl;
	cout << "\t\t3.����ϵ" << endl;
	cout << "����Ҫ��ѯ��ϵ:"<<endl;
	cin >> i;
	getchar();
	switch (i) {
	case 1:	
		while (p) {
		if(p->flage == TRUE)
			if (p->t->get_faculty()== "����ϵ")
				cout << *(p->t) << endl;
		p=p->next;
	}
		break;
	case 2:
		while (p) {
			if(p->flage == TRUE)
				if (p->t->get_faculty() == "����ϵ")
					cout << *(p->t) << endl;
			p = p->next;
		}
		break;
	default:
		while (p) {
			if(p->flage == TRUE)
				if (!(p->t->get_faculty() == "����ϵ"|| p->t->get_faculty() == "����ϵ") )
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
	t1.set_name("������");
	t1.set_sex("��");
	t1.set_salary(8000);
	t1.set_birthandage(1994);
	t1.set_department("�Ϻ�ѧԺ");
	t1.set_worktime(20150621);
	t1.set_faculty("����ϵ");


	t2.set_num("10087");
	t2.set_name("Ǯ����");
	t2.set_sex("��");
	t2.set_salary(10000);
	t2.set_birthandage(1987);
	t2.set_department("�Ϻ�ѧԺ");
	t2.set_worktime(20140508);
	t2.set_faculty("��ѧϵ");


	t3.set_num("10088");
	t3.set_name("�����");
	t3.set_sex("Ů");
	t3.set_salary(9000);
	t3.set_birthandage(1990);
	t3.set_department("�Ϻ�ѧԺ");
	t3.set_worktime(20150311);
	t3.set_faculty("��ѧϵ");

	
	t4.set_num("10089");
	t4.set_name("�� ˹");
	t4.set_sex("��");
	t4.set_salary(7000);
	t4.set_birthandage(1992);
	t4.set_department("�Ϻ�ѧԺ");
	t4.set_worktime(20150701);
	t4.set_faculty("����ϵ");


	t5.set_num("10090");
	t5.set_name("������");
	t5.set_sex("��");
	t5.set_salary(8000);
	t5.set_birthandage(1995);
	t5.set_department("�Ϻ�ѧԺ");
	t5.set_worktime(20150702);
	t5.set_faculty("����ϵ");

	w1.set_num("10065");
	w1.set_name("�� ��");
	w1.set_sex("��");
	w1.set_salary(10000);
	w1.set_birthandage(1996);
	w1.set_department("����ѧԺ");
	w1.set_worktime(20150702);
	w1.set_job("����ʦ");


	w2.set_num("10066");
	w2.set_name("�����");
	w2.set_sex("��");
	w2.set_salary(6000);
	w2.set_birthandage(1994);
	w2.set_department("����ѧԺ");
	w2.set_worktime(20140308);
	w2.set_job("����");


	w3.set_num("10067");
	w3.set_name("�⺣��");
	w3.set_sex("Ů");
	w3.set_salary(8000);
	w3.set_birthandage(1990);
	w3.set_department("�Ϻ�ѧԺ");
	w3.set_worktime(20150409);
	w3.set_job("ͼ�����Ա");


	w4.set_num("10069");
	w4.set_name("�� ��");
	w4.set_sex("��");
	w4.set_salary(9000);
	w4.set_birthandage(1988);
	w4.set_department("����ѧԺ");
	w4.set_worktime(20150105);
	w4.set_job("ϵͳ����Ա");


	w5.set_num("10096");
	w5.set_name("�� ��");
	w5.set_sex("��");
	w5.set_salary(9000);
	w5.set_birthandage(1988);
	w5.set_department("����ѧԺ");
	w5.set_worktime(20150105);
	w5.set_job("ϵͳ����Ա");

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