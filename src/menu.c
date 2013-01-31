#include "menu.h"
void menu(GINFO *pginfo)
{
	int sw=0;
	while(1)
	{
		system("clear");
		printf("------------Personnel Management System-----------\n");	
		printf("1.员工信息操作\n");
		printf("2.员工奖惩操作\n");
		printf("3.计算员工工资\n");
		printf("4.退出\n");
		printf("请输入选项:");
		while(scanf("%d",&sw)==0)
		{
			printf("请输入正确的选项:");
			while(getchar()!='\n');
		}
		switch(sw)
		{
		case 1:
			op_eminfo(pginfo->em_head);
			break;
		case 2:
	//		op_rpinfo(pginfo->rp_head);
			break;
		case 3:
//			calc_em_salary(pginfo);
			break;
		case 4:
			return ;	
		default:
			printf("请输入正确的选项:");
			break;
		}
	}
	return;
}
int op_eminfo(EMPLOYEE* em_head)
{	
	int sw=0;
	while(1)
	{
		system("clear");
		setbuf(stdin,NULL);
		printf("***************员工信息操作***************\n");
		printf("1.查看员工信息\n");
		printf("2.添加员工信息\n");
		printf("3.删除员工信息\n");
		printf("4.返回上层\n");
		printf("请输入选项:");
		while(scanf("%d",&sw)==0)
		{
			printf("请输入正确的选项:");
			while(getchar()!='\n');
		}
		switch(sw)
		{
		case 1:
			show_all_eminfo(em_head);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
		default:
			printf("请输入正确的选项:");
			break;
		}
	}
	return 0;
}
void show_all_eminfo(EMPLOYEE* em_head)
{
	EMPLOYEE* ptmp=em_head;
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
	if(pem==NULL)
	{
		return ;
	}
	printf("ID:%d\n",pem->id);
	printf("姓名:%s\n",pem->name);
	printf("职称:%s\n",pem->title);
	printf("基本薪资:%d",pem->salay);
	if(pem->online)
	{
		printf("工作状态:在职\n");
	}
	else
	{
		
		printf("工作状态:离职\n");
	}
}
