#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
int emid=0;
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
		if((ptmp->online==1))
		{
			show_employee(ptmp);
		}
		ptmp=ptmp->next;
	}
	setbuf(stdin,NULL);
	getchar();
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
		ptmp=ptmp->next;
	}
	return count;
}
int delete_em_by_id(EMPLOYEE* em_head,int id)
{
	EMPLOYEE* ptemp=em_head;
	if(ptemp==NULL)
	{
		fprintf(stderr,"employee list error\n");
		exit(1);
	}
	while(ptemp->next!=NULL)
	{
		if(ptemp->next->id==id)
		{
			ptemp->next->online=0;	
			return 1;
		}
		ptemp=ptemp->next;
	}
	return 0;
}
