#include <stdlib.h>
#include "menu.h"
void menu(GINFO *pginfo)
{
	int sw=0;
	FILE *fpem=NULL;
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
			fpem=fopen("../data/emdata","r+");			
			if(fpem==NULL)	
			{
				fprintf(stderr,"打开员工信息文件失败!\n");
				exit(0);
			}
			pginfo->em_count=get_employee_count(pginfo->em_head);
			save_all(fpem,pginfo);
			fclose(fpem);
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
	int dirtydata=0;//标记有无脏数据
	EMPLOYEE* pem=NULL;
	FILE *fpem=NULL;
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
			pem=input_one_employee();
			if(add_employee(em_head,pem)==1)
			{
				dirtydata=1;	
			}
			break;
		case 3:
			break;
		case 4:
			if(dirtydata==1)
			{
				fpem=fopen("../data/emdata","r+");			
				if(fpem==NULL)	
				{
					fprintf(stderr,"打开员工信息文件失败!\n");
					exit(0);
				}
				save_employees(fpem,em_head);
				fclose(fpem);
			}
			return;
		default:
			printf("请输入正确的选项:");
			break;
		}
	}
	return 0;
}

