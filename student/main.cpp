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
//主要函数
void input_record();//输入
int updata_record();//修改
void add_record();//增加
int insert_record();//插入
int  delete_record();//删除
int search_record();//查询
int soft_record();//排序
int count_record();//统计
void show_record();//输出
void save_to_file();//保存
//辅助函数
void input_student();//输入学生数据
void output_student(stu *p);//输出学生数据
void change_student(stu *q, stu *p);//交换数据
int soft_up();//升序
int soft_down();//降序


void main() {
	int choose;
	while (1) {
		printf("\t**********学生档案管理*********\n");
		printf("\t-------------------------------\n");
		printf("\t|-----------1.输入------------|\n");
		printf("\t|-----------2.修改------------|\n");
		printf("\t|-----------3.增加------------|\n");
		printf("\t|-----------4.插入------------|\n");
		printf("\t|-----------5.删除------------|\n");
		printf("\t|-----------6.查询------------|\n");
		printf("\t|-----------7.排序------------|\n");
		printf("\t|-----------8.统计------------|\n");
		printf("\t|-----------9.输出------------|\n");
		printf("\t|-----------0.保存------------|\n");
		printf("\t-------------------------------\n");
		printf("请选择:");
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




//主函数定义
void input_record() {
	//head = (stu *)malloc(sizeof(stu));
	//head->next = NULL;
	input_student();
	char choose;
	while (1) {
		printf("是否继续输入数据 Y or N\n");
		scanf_s("%c", &choose);
		if (choose == 'y' || choose == 'Y')
			input_student();
		else break;
	}

}

void show_record() {
	if (!head) printf("请先输入数据\n");
	else {
		stu *p = head;
		printf("+----------+----------+----+----------+----------+\n");
		printf("|   学号   |  姓名    |性别| 出生日期 | 家庭地址 +\n");
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
	if (!head) { printf("请先输入数据\n"); return 0; }
	else {
		printf("请输入要修改学生的学号:");
		getchar();
		gets_s(num1);
		p = head;
		while (p) {
			if (strcmp(num1, p->num)) p = p->next;
			else break;
		}

	}
	if (p == NULL) printf("此学生不存在\n");
	else {
		printf("查询学生为%s\n", p->name);
		printf("请修改性别F or M:");
		gets_s(p->sex);
		printf("请修改出生日期:");
		gets_s(p->birth);
		printf("请修改地址:");
		gets_s(p->address);
	}
	printf("是否继续输入数据 Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		updata_record();
	return 0;

}

void add_record() {
	if (!head) printf("请先输入数据\n");
	else input_student();
	printf("是否继续输入数据 Y or N\n");
	char choose;
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		add_record();
}
int insert_record() {
	char num1[max];
	char choose;
	stu *p,*q;
	if (!head) { printf("请先输入数据\n"); return 0; }
	printf("请输入在哪个学号后面插入数据\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p)
	{
		if (strcmp(num1, p->num)) { q = p; p = p->next; }
		else break;
	}
	if (p == NULL) printf("此学生不存在\n");
	else {
		stu *L;
		L = (stu *)malloc(sizeof(stu));
		printf("请输入学号:");
		gets_s(L->num);
		printf("请输入姓名:");
		gets_s(L->name);
		printf("请输入性别F or M:");
		gets_s(L->sex);
		printf("请输入出生日期:");
		gets_s(L->birth);
		printf("请输入地址:");
		gets_s(L->address);
		q->next = L;
		L->next = p;
	}
	printf("是否继续输入数据 Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		insert_record();
	return 0;
}

int delete_record() {
	char num1[max];
	stu *p;
	int choose;
	if (!head) { printf("请先输入数据\n"); return 0; }
	else {
		printf("请输入要删除学生的学号\n");
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
			printf("此学生不存在\n");
		else
		{
			head=head->next;
			free(p);
		}
	}
	printf("是否继续输入数据 Y or N\n");
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
	if (!head) { printf("请先输入数据\n"); return 0; }
	printf("***1.  学号    ***\n");
	printf("***2.  姓名    ***\n");
	printf("***3.学号区间段***\n");
	printf("***4. 家庭地址 ***\n");
	printf("请选择要查询的类型:");
	scanf_s("%d", &i);
	switch (i) {
	case 1:
	{printf("请输入要查询的学号\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p) {
		if (strcmp(num1, p->num)) p = p->next;
		else break;
	}
	if (p == NULL)
		printf("此学生不存在\n");
	else
		output_student(p);
	break; }
	case 2:
	{printf("请输入要查询的姓名\n");
	getchar();
	gets_s(num1);
	p = head;
	while (p) {
		if (strcmp(num1, p->name)) p = p->next;
		else break;
	}
	if (p == NULL)
		printf("此学生不存在\n");
	else
		output_student(p);
	break; }
	case 3:
	{printf("请输入要查询的学号区间段\n");
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
	printf("查询结束\n");
	break; }
	case 4:
	{printf("请输入要查询的地址\n");
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
	printf("是否继续输入数据 Y or N\n");
	scanf_s("%c", &choose);
	if (choose == 'y' || choose == 'Y')
		search_record();
	return 0;
}
int soft_record() {
	if (!head) { printf("请先输入数据\n"); return 0; }
	int choose;
	printf("****1.升序****\n");
	printf("****2.降序****\n");
	printf("请选择你想要的排序\n");
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
	if (!head) { printf("请先输入数据\n"); return 0; }
	stu *p = head;
	while (p)
	{
		if (!strcmp(sex1, strupr(p->sex))) count1++;
		else if (!strcmp(sex2, strupr(p->sex))) count2++;
		else printf("学生%s的性别为'%s'不是要求的M或F\n", p->name, p->sex);
		p = p->next;
	}
	printf("男生的数量为%d，女生的数量为%d，男生所占比例为%.2f%%\n", (int)count1, (int)count2, count1 * 100 / (count1 + count2));
	return 0;

}
void save_to_file() {
	FILE *fp;
	char file[100];
	stu *p = head;
	printf("请输入文件名");
	getchar();
	gets_s(file);
	fp = fopen(file, "w");
	while (p != NULL)
	{
		fprintf(fp, "%s,%s,%s,%s,%s\n", p->num, p->name, p->sex, p->birth, p->address);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功\n");
	printf("是否退出 1.是 2.否\n");
	int choose;
	scanf("%d", &choose);
	getchar();
	if (choose == 1) exit(1);
}

//辅助函数定义
void input_student() {
	stu *L;
	L = (stu *)malloc(sizeof(stu));
	getchar();
	printf("请输入学号:");
	gets_s(L->num);
	printf("请输入姓名:");
	gets_s(L->name);
	printf("请输入性别F or M:");
	gets_s(L->sex);
	printf("请输入出生日期:");
	gets_s(L->birth);
	printf("请输入地址:");
	gets_s(L->address);
	
	L->next = head;
	head = L;
}
void output_student(stu *p) {
	printf("+----------+----------+----+----------+----------+\n");
	printf("|   学号   |  姓名    |性别| 出生日期 | 家庭地址 +\n");
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