#include <stdio.h>
#include <stdlib.h>
void menu()
{
	int sw=0;
	system("clear");
	while(1)
	{
		printf("\t\t------------Personnel Management System-----------\n");	
		printf("\t\t1.员工信息操作\n");
		printf("\t\t2.员工奖惩操作\n");
		printf("\t\t3.员工奖惩信息查看\n");
		printf("\t\t4.退出\n");
		printf("请输入选项:");
		while(scanf("%d",&sw)==0)
		{
			printf("请输入正确的选项:");
			while(getchar()!='\n');
		}
		switch(sw)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			printf("请输入正确的选项:");
			break;
		}
	}
	return;
}
