/*
*初始化系统,读取数据文件,创建员工链表与奖惩链表
*/
int init_sys()
{
	FILE *fpem;
	FILE *fprp;
	GINFO ginfo;
	if(init_files(&fpem,&fprp)==0)
	{
		save_all(fp,);
	}
}
/*
*找不到文件返回0,找到文件返回1
*/
int init_files(FILE **fpem,FILE **fpre)
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
	return 1;
}
