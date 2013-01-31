#include "rewardpunish.h"

void show_all_rwinfo(RP* rp_head)//显示所有在职人员奖惩记录
{
	RP *ptmp=rp_head->next;
	if(ptmp==NULL)
	{
		printf("暂无奖惩记录\n");
		setbuf(stdin,NULL);
		getchar();
		return;
	}
	while(ptmp!=NULL)
	{
		if((ptmp->online==1))
		{
			show_rewardpunish(ptmp);
		}
		ptmp=ptmp->next;
	}
	setbuf(stdin,NULL);
	getchar();
	return ;
}
void show_rwinfo_by_id(RP *em_head,int id)
{
	int showflag=0;
	RP *ptmp=rp_head->next;
	if(ptmp==NULL)
	{
		printf("暂无奖惩记录\n");
		setbuf(stdin,NULL);
		getchar();
		return;
	}
	while(ptmp!=NULL)
	{
		if((ptmp->id==id) && (ptmp->online==1))
		{
			show_rewardpunish(ptmp);
			showflag=1;
		}
		ptmp=ptmp->next;
	}
	if(showflag==0)
	{
		printf("该员工暂无奖惩记录\n");
	}
	setbuf(stdin,NULL);
	getchar();
}
void show_rewardpunish(RP* prp)
{
	printf("工号: %d\n",prp->id);
	if(prp->money>=0)
	{
		printf("奖励: %d元\n",prp->money);
	}
	else
	{
		printf("惩罚: %d元\n",prp->money*-1);
	}
	printf("日期: %s\n",prp->date);
	printf("详细描述: %s\n",prp->description);
}
int get_rewardpunish_count(RP* rp_head)
{
	itn count=0;
	if(rp_head==NULL)
	{
		fprintf(stderr,"奖惩记录链表错误");
		reuturn 0;
	}
	RP *ptmp=rp_head;
	while(ptmp->next!=NULL)
	{
		count++;
		ptmp=ptmp->next;
	}
	return count;
}
int delte_rewardpunish_by_id(RP* rp_head,int id)
{
	int dirtyflag=0;
	RP *ptemp=rp_head;
	if(ptemp==NULL)
	{
		fprintf(stderr,"rp list error\n");
		exit(1);
	}
	while(ptemp->next!=NULL)
	{
		if(ptemp->next->id==id)
		{
			ptemp->next->online=0;
			dirtyflag=1;
		}
		ptemp=ptemp->next;
	}
	return dirtyflag;
}

