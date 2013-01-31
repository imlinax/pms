#ifndef _EMPLOYEES_H
#define _EMPLOYEES_H

#define EMP_SAVE_SIZE (sizeof(EMPLOYEE)-sizeof(EMPLOYEE*))
typedef struct employee
{
	int  id;//工号
	char name[32];//姓名
	int  title;//职称1.初级2.高级3.高级
	int  salay;//基本薪资
	int online;//标志是否还在公司工作
	struct employee* next;//指向下一个员工
}EMPLOYEE;

void show_all_eminfo(EMPLOYEE* em_head);
void show_employee(EMPLOYEE* pem);
int get_employee_count(EMPLOYEE* em_head);

extern int emid;


#endif
