#include <stdio.h>
#include "pmsio.h"
EMPLOYEE *input_one_employee()
{
	int title=-1;
	EMPLOYEE* pem=(EMPLOYEE*)main(sizeof(EMPLOYEE));
	printf("请输入员工姓名:");
	scanf("%31s",pem->name);
	printf("员工职称\n1.初级\t2.高级\t\3.高级\n请选择:");
	while(scanf("%d",&title)==0)
	{
		printf("请输入正确选项:");
	}
	pem->title=title;
	pem->salay=1000*title;
	pem->online=1;

}
RP * input_one_rewardpunish()
{
	
}
