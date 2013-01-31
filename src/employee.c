#include <stdio.h>
#include "employee.h"
void show_all_eminfo(EMPLOYEE* em_head)
{
	EMPLOYEE* ptmp=em_head->next;
	if(ptmp==NULL)
	{
		printf("暂无员工信息\n");
		setbuf(stdin,NULL);
		getchar();
		return ;
	}
	while(ptmp!=NULL)
	{
		show_employee(ptmp);
		ptmp=ptmp->next;
	}
	return ;
}
void show_employee(EMPLOYEE* pem)
{
	char *title[]={"初级","中级","高级"};
	if(pem==NULL)
	{
		return ;
	}
	printf("ID:%d\n",pem->id);
	printf("姓名:%s\n",pem->name);
	printf("职称:%s\n",title[pem->title]);
	printf("基本薪资:%d元\n",pem->salay);
	if(pem->online)
	{
		printf("工作状态:在职\n");
	}
	else
	{
		
		printf("工作状态:离职\n");
	}
}
int add_employee(EMPLOYEE *em_head,EMPLOYEE *pem)
{
	EMPLOYEE *ptmp=em_head;
	if(pem==NULL)
	{
		fprintf(stderr,"员工信息为空,添加失败\n");
		return  0 ;
	}
	while(ptmp->next!=NULL)
	{
		ptmp=ptmp->next;
	}
	pem->next=NULL;
	ptmp->next=pem;
	return 1;
}

int get_employee_count(EMPLOYEE* em_head)
{
	int count=0;
	if(em_head==NULL)
	{
		fprintf(stderr,"员工链表错误");
		return 0;
	}
	EMPLOYEE *ptmp=em_head;
	while(ptmp->next!=NULL)	
	{
		count++;
	}
	return count;
}
