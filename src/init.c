#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "fileop.h"
#include "init.h"
/*
*初始化系统,读取数据文件,创建员工链表与奖惩链表
*/
GINFO* init_sys()
{
	FILE *fpem;
	FILE *fprp;
	GINFO* pginfo=(GINFO *)malloc(sizeof(GINFO));
	pginfo->em_count=0;
	pginfo->rp_count=0;
	pginfo->em_head=NULL;
	pginfo->rp_head=NULL;
	if(init_files(&fpem,&fprp)==0)
	{
		save_all(fpem,pginfo);
		save_all(fprp,pginfo);
//		fclose(fpem);
//		fclose(fprp);
	//	return 0;
	}
	pginfo=load_all(fpem,fprp);
	fclose(fpem);
	fclose(fprp);
	return pginfo;
}
/*
*找不到文件返回0,找到文件返回1
*/
int init_files(FILE **fpem,FILE **fprp)
{
	FILE *fp_employee=NULL;
	FILE *fp_rewardpunish=NULL;
	fp_employee=fopen("../data/emdata","rb");
	fp_rewardpunish=fopen("../data/rpdata","rb");
	if((fp_employee==NULL) || (fp_rewardpunish==NULL))
	{
		fp_employee=fopen("../data/emdata","wb+");
		if(fp_employee==NULL)
		{
			fprintf(stderr,"无法创建文件!\n");
			exit(1);
		}
		fp_rewardpunish=fopen("../data/rpdata","wb+");
		{
			if(fp_rewardpunish==NULL)
			{
				fprintf(stderr,"无法创建文件!\n");
				exit(1);
			}
		}
		*fpem=fp_employee;
		*fprp=fp_rewardpunish;
		return 0;
	}
	*fpem=fp_employee;
	*fprp=fp_rewardpunish;

	return 1;
}
