#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "rewardpunish.h"
#include "global.h"
/*
*加载存在文件中的所有信息
*/
GINFO	 *load_all(FILE *fpem,FILE *fpep)
{
	GINFO *pginfo=(GINFO*)malloc(sizeof(GINFO));
	if(fread(pginfo,sizeof(GINFO),1,fpem)<1)
	{
		fprintf(stderr,"加载配置文件失败!\n");
		exit(1);
	}
	pginfo->em_head=load_employees(fpem,pginfo->em_count);
	pginfo->rm_head=load_rewardpunish(fprp,pginfo->rp_count);

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
	EMPLOYEE* phead=(EMPLOYEE*)malloc(EMP_SAVE_SIZE);
	EMPLOYEE* ptmp=phead;
	fseek(fp,sizeof(GINFO),SEEK_SET);
	if(ptmp==NULL)
	{
		exit(1);
	}
	for(i=0;i<count-1;i++)
	{
		fread(ptmp,sizeof(EMP_SAVE_SIZE),1,fp);
		ptmp->next=(EMPLOYEE*)malloc(EMP_SAVE_SIZE);
		if(ptmp->next==NULL)
		{
			fprintf(stderr,"memory allocation error!\n");
			exit(1);
		}
		ptmp=ptmp->next;
	}
	fread(ptmp,sizeof(EMP_SAVE_SIZE),1,fp);
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
	RP * phead=(RP*)malloc(RP_SAVE_SIZE);
	RP * ptmp=phead;
	fseek(fp,sizeof(GINFO),SEEK_SET);
	if(ptmp==NULL)
	{
		exit(1);
	}
	for(i=0;i<count-1;i++)
	{
		fread(ptmp,sizeof(RP_SAVE_SIZE),1,fp);
		ptmp->next=(RP*)malloc(RP_SAVE_SIZE);
		if(ptmp->next==NULL)
		{
			fprintf(stderr,"memory allocation error!\n");
			exit(1);
		}
		ptmp=ptmp->next;
	}
	fread(ptmp,sizeof(RP_SAVE_SIZE),1,fp);
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
}
/*
*存储所有员工信息到文件中
*/
int save_employees(FILE *fp,EMPLOYEE*);
/*
*存储所有奖惩记录到文件中
*/
int save_rewardpunish(FILE *fp,RP* prp)
{
	;
}



