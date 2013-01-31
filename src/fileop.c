#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "rewardpunish.h"
#include "global.h"
#include "fileop.h"
/*
*加载存在文件中的所有信息
*/
GINFO	 *load_all(FILE *fpem,FILE *fprp)
{
	GINFO *pginfo=(GINFO*)malloc(sizeof(GINFO));
	fseek(fpem,0,SEEK_SET);
	fseek(fprp,0,SEEK_SET);
	if(fread(pginfo,sizeof(GINFO),1,fpem)<1)
	{
		fprintf(stderr,"加载配置文件失败!\n");
		exit(1);
	}
	pginfo->em_head=load_employees(fpem,pginfo->em_count);
	pginfo->rp_head=load_rewardpunish(fprp,pginfo->rp_count);

	return pginfo;
}/*
*加载所有员工
*@count:要读取的员工数
*/
EMPLOYEE *load_employees(FILE *fp,int count)
{
	int i=0;
	if(count<1)
	{
		return NULL;
	}
	EMPLOYEE* phead=(EMPLOYEE*)calloc(1,EMP_SAVE_SIZE);
	EMPLOYEE* ptmp=phead;
	fseek(fp,sizeof(GINFO),SEEK_SET);
	if(phead==NULL)
	{
		exit(1);
	}
	for(i=0;i<count;i++)
	{
		ptmp->next=(EMPLOYEE*)malloc(EMP_SAVE_SIZE);
		if(ptmp->next==NULL)
		{
			fprintf(stderr,"memory allocation error!\n");
			exit(1);
		}
		fread(ptmp->next,sizeof(EMP_SAVE_SIZE),1,fp);
		ptmp=ptmp->next;
	}
	ptmp->next=NULL;
	return phead;
}
/*
*加载所有奖惩记录
*/
RP *load_rewardpunish(FILE *fp,int count)
{
	int i=0;
	if(count<1)
	{
		return NULL;
	}
	RP * phead=(RP*)calloc(1,RP_SAVE_SIZE);
	RP * ptmp=phead;
	fseek(fp,sizeof(GINFO),SEEK_SET);
	if(ptmp==NULL)
	{
		exit(1);
	}
	for(i=0;i<count;i++)
	{
		ptmp->next=(RP*)malloc(RP_SAVE_SIZE);
		if(ptmp->next==NULL)
		{
			fprintf(stderr,"memory allocation error!\n");
			exit(1);
		}
		fread(ptmp->next,sizeof(RP_SAVE_SIZE),1,fp);
		ptmp=ptmp->next;
	}
	ptmp->next=NULL;
	return phead;
}
/*
*存储所有信息到文件中,包括全局变量

*/
int save_all(FILE *fp,GINFO* pginfo)
{
	if(fp==NULL)
	{
		return 0;
	}
	fseek(fp,0,SEEK_SET);
	if(fwrite(pginfo,sizeof(GINFO),1,fp)!=1)
	{
		fprintf(stderr,"save file error!\n");
		exit(1);
	}
	return 1;
}
/*
*存储所有员工信息到文件中
*/
int save_employees(FILE *fp,EMPLOYEE* em_head)
{
	EMPLOYEE* pem=em_head->next;
	if(fp==NULL)
	{
		return 0;
	}
	fseek(fp,sizeof(GINFO),SEEK_SET);
	while(pem!=NULL)
	{
		if(fwrite(pem,sizeof(EMP_SAVE_SIZE),1,fp)!=1)
		{
			fprintf(stderr,"save file error!\n");
			exit(0);
		}
	}
	return 1;
}
/*
*存储所有奖惩记录到文件中
*/
int save_rewardpunish(FILE *fp,RP* prp)
{
	;
}



