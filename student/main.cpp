#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10

typedef struct student {
	char num[max];
	char name[max];
	char sex[max];
	char birth[max];
	char address[max];
	struct student *next;
}stu;
stu *head = NULL;
//��Ҫ����
void input_record();//����
int updata_record();//�޸�
void add_record();//����
int insert_record();//����
int  delete_record();//ɾ��
int search_record();//��ѯ
int soft_record();//����
int count_record();//ͳ��
void show_record();//���
void save_to_file();//����
//��������
void input_student();//����ѧ������
void output_student(stu *p);//���ѧ������
void change_student(stu *q, stu *p);//��������
int soft_up();//����
int soft_down();//����


void main() {
	int choose;
	while (1) {
		printf("\t**********ѧ����������*********\n");
		printf("\t-------------------------------\n");
		printf("\t|-----------1.����------------|\n");
		printf("\t|-----------2.�޸�------------|\n");
		printf("\t|-----------3.����------------|\n");
		printf("\t|-----------4.����------------|\n");
		printf("\t|-----------5.ɾ��------------|\n");
		printf("\t|-----------6.��ѯ------------|\n");
		printf("\t|-----------7.����------------|\n");
		printf("\t|-----------8.ͳ��------------|\n");
		printf("\t|-----------9.���------------|\n");
		printf("\t|-----------0.����------------|\n");
		printf("\t-------------------------------\n");
		printf("��ѡ��:");
		scanf_s("%d", &choose);
		switch (choose) {
		case 1:input_record(); break;
		case 2:updata_record(); break;
		case 3:add_record(); break;
		case 4:insert_record(); break;
		case 5:delete_record(); break;
		case 6:search_record(); break;
		case 7:soft_record(); break;
		case 8:count_record(); break;
		case 9:show_record(); break;
		case 0:save_to_file(); break;
		}
	}
}




//����������
void input_record() {
	//head = (stu *)malloc(sizeof(stu));
	//head->next = NULL;
	input_student();
	char choose;
	while (1) {
		printf("�Ƿ������������ Y or N\n");
		scanf_s("%c", &choose);
		if (choose == 'y' || choose == 'Y')
			input_student();
		else break;
	}

}

void show_record() {
	if (!head) printf("������������\n");
	else {
		stu *p = head;
		printf("+----------+----------+----+----------+----------+\n");
		printf("|   ѧ��   |  ����    |�Ա�| �������� | ��ͥ��ַ +\n");
		while (p)
		{
			printf("|%-10s|%-10s|%-4s|%-10s|%-10s|\n", p->num, p->name, p->sex, p->birth, p->address);
			p = p->next;
		}
		printf("+----------+----------+----+----------+----------+\n");
	}

}

int updata_record() {
	char num1[max];
	char choose;
	stu *p;
	if (!head) { printf("������������\n"); return 0; }
	else {
		printf("������Ҫ�޸�ѧ����ѧ��:");
		getchar();
		gets_s(num1);
		p = head;
		while (p) {
			if (strcmp(num1, p->num)) p = p->next;
			else break;
		}

	}
	if (p == NULL) printf("��ѧ��������\n");
	else {
		printf("��ѯѧ��Ϊ%s\n", p->name);
		printf("���޸��Ա�F or M:");
		gets_s(p->sex);
		printf("���޸ĳ�������:");
		gets_s(p->birth);
		printf("���޸ĵ�ַ:");
		gets_s(p->address);
	}
	printf("�Ƿ������������ Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		updata_record();
	return 0;

}

void add_record() {
	if (!head) printf("������������\n");
	else input_student();
	printf("�Ƿ������������ Y or N\n");
	char choose;
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		add_record();
}
int insert_record() {
	char num1[max];
	char choose;
	stu *p,*q;
	if (!head) { printf("������������\n"); return 0; }
	printf("���������ĸ�ѧ�ź����������\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p)
	{
		if (strcmp(num1, p->num)) { q = p; p = p->next; }
		else break;
	}
	if (p == NULL) printf("��ѧ��������\n");
	else {
		stu *L;
		L = (stu *)malloc(sizeof(stu));
		printf("������ѧ��:");
		gets_s(L->num);
		printf("����������:");
		gets_s(L->name);
		printf("�������Ա�F or M:");
		gets_s(L->sex);
		printf("�������������:");
		gets_s(L->birth);
		printf("�������ַ:");
		gets_s(L->address);
		q->next = L;
		L->next = p;
	}
	printf("�Ƿ������������ Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		insert_record();
	return 0;
}

int delete_record() {
	char num1[max];
	stu *p;
	int choose;
	if (!head) { printf("������������\n"); return 0; }
	else {
		printf("������Ҫɾ��ѧ����ѧ��\n");
		getchar();
		gets_s(num1);
		while (head)
		{		p = head;
			if (strcmp(num1, p->num))
			{
				head = p->next;
				free(p);
			}
			else break;
		}
		if (head == NULL)
			printf("��ѧ��������\n");
		else
		{
			head=head->next;
			free(p);
		}
	}
	printf("�Ƿ������������ Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		delete_record();
	return 0;

}
int search_record() {
	char num1[max], num2[max];
	char choose;
	int  i;
	stu *p;
	if (!head) { printf("������������\n"); return 0; }
	printf("***1.  ѧ��    ***\n");
	printf("***2.  ����    ***\n");
	printf("***3.ѧ�������***\n");
	printf("***4. ��ͥ��ַ ***\n");
	printf("��ѡ��Ҫ��ѯ������:");
	scanf_s("%d", &i);
	switch (i) {
	case 1:
	{printf("������Ҫ��ѯ��ѧ��\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p) {
		if (strcmp(num1, p->num)) p = p->next;
		else break;
	}
	if (p == NULL)
		printf("��ѧ��������\n");
	else
		output_student(p);
	break; }
	case 2:
	{printf("������Ҫ��ѯ������\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p) {
		if (strcmp(num1, p->name)) p = p->next;
		else break;
	}
	if (p == NULL)
		printf("��ѧ��������\n");
	else
		output_student(p);
	break; }
	case 3:
	{printf("������Ҫ��ѯ��ѧ�������\n");
	getchar();
	scanf_s("%s", &num1);
	getchar();
	scanf_s("%s", &num2);
	getchar();
	p = head;
	while (p) {
		if (strcmp(num1, p->num) <= 0 && strcmp(num2, p->num) >= 0)
		{
			output_student(p);
			p = p->next;
		}
		else p = p->next;
	}
	printf("��ѯ����\n");
	break; }
	case 4:
	{printf("������Ҫ��ѯ�ĵ�ַ\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p) {
		if (!strcmp(num1, p->address))
		{
			output_student(p); p = p->next;
		}
		else p = p->next;
	}
	break; }
	}
	printf("�Ƿ������������ Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		search_record();
	return 0;
}
int soft_record() {
	if (!head) { printf("������������\n"); return 0; }
	int choose;
	printf("****1.����****\n");
	printf("****2.����****\n");
	printf("��ѡ������Ҫ������\n");
	scanf_s("%d", &choose);
	switch (choose) {
	case 1:soft_up(); break;
	case 2:soft_down(); break;
	}
	return 0;
}
int count_record() {
	float count1 = 0, count2 = 0;
	char sex1[max] = "F", sex2[max] = "M";
	if (!head) { printf("������������\n"); return 0; }
	stu *p = head;
	while (p)
	{
		if (!strcmp(sex1, strupr(p->sex))) count1++;
		else if (!strcmp(sex2, strupr(p->sex))) count2++;
		else printf("ѧ��%s���Ա�Ϊ'%s'����Ҫ���M��F\n", p->name, p->sex);
		p = p->next;
	}
	printf("����������Ϊ%d��Ů��������Ϊ%d��������ռ����Ϊ%.2f%%\n", (int)count1, (int)count2, count1 * 100 / (count1 + count2));
	return 0;

}
void save_to_file() {
	FILE *fp;
	char file[100];
	stu *p = head;
	printf("�������ļ���");
	getchar();
	gets_s(file);
	fp = fopen(file, "w");
	while (p != NULL)
	{
		fprintf(fp, "%s,%s,%s,%s,%s\n", p->num, p->name, p->sex, p->birth, p->address);
		p = p->next;
	}
	fclose(fp);
	printf("����ɹ�\n");
	printf("�Ƿ��˳� 1.�� 2.��\n");
	int choose;
	scanf("%d", &choose);
	getchar();
	if (choose == 1) exit(1);
}

//������������
void input_student() {
	stu *L;
	L = (stu *)malloc(sizeof(stu));
	getchar();
	printf("������ѧ��:");
	gets_s(L->num);
	printf("����������:");
	gets_s(L->name);
	printf("�������Ա�F or M:");
	gets_s(L->sex);
	printf("�������������:");
	gets_s(L->birth);
	printf("�������ַ:");
	gets_s(L->address);
	
	L->next = head;
	head = L;
}
void output_student(stu *p) {
	printf("+----------+----------+----+----------+----------+\n");
	printf("|   ѧ��   |  ����    |�Ա�| �������� | ��ͥ��ַ +\n");
	printf("|%-10s|%-10s|%-4s|%-10s|%-10s|\n", p->num, p->name, p->sex, p->birth, p->address);
	printf("+----------+----------+----+----------+----------+\n");
}

int soft_up() {
	stu *p = head;
	stu *q = p;
	bool flag = false;
	while (q->next != NULL)
	{
		char temp[max];
		strcpy(temp, q->num);
		p = p->next;
		while (p)
		{
			if (strcmp(temp, p->num) <= 0)
			{
				p = p->next;
				continue;
			}
			else
			{
				change_student(q, p);
				p = p->next;
				strcpy(temp, q->num);
				flag = true;
			}
			if (flag == false)
				return 0;
		}
		q = q->next;
		p = q;
	}
	show_record();
	return 0;
}
int soft_down() {
	stu *p = head;
	stu *q = p;
	bool flag = false;
	while (q->next != NULL)
	{
		char temp[max];
		strcpy(temp, q->num);
		p = p->next;
		while (p)
		{
			if (strcmp(temp, p->num) >= 0)
			{
				p = p->next;
				continue;
			}
			else
			{
				change_student(q, p);
				p = p->next;
				strcpy(temp, q->num);
				flag = true;
			}
			if (flag == false)
				return 0;
		}
		q = q->next;
		p = q;
	}
	show_record();
	return 0;
}
void change_student(stu *q, stu *p)
{

	stu *temp_change;
	temp_change = (stu *)malloc(sizeof(stu));
	strcpy(temp_change->num, p->num);
	strcpy(p->num, q->num);
	strcpy(q->num, temp_change->num);

	strcpy(temp_change->name, p->name);
	strcpy(p->name, q->name);
	strcpy(q->name, temp_change->name);

	strcpy(temp_change->sex, p->sex);
	strcpy(p->sex, q->sex);
	strcpy(q->sex, temp_change->sex);

	strcpy(temp_change->birth, p->birth);
	strcpy(p->birth, q->birth);
	strcpy(q->birth, temp_change->birth);

	strcpy(temp_change->address, p->address);
	strcpy(p->address, q->address);
	strcpy(q->address, temp_change->address);

	free(temp_change);

}