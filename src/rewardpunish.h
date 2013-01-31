#ifndef _REWARDPUNISH_H
#define _REWARDPUNISH_H

/*不使用rpflag*/
#ifdef _RPFLAG
#undef _RPFLAG
#endif


#define RP_SAVE_SIZE (sizeof(RP))	//保存到文件时丢弃next指针

typedef struct reward_punish
{
	int id;//工号
	#ifdef _RPFLAG 
	int rpflag;
	#endif
	int money;//奖惩多少钱,正数为奖,负数为惩
	char date[12];//日期
	char description[128];//描述
	int online;//标志该奖惩方式是否还有效
	struct reward_punish* next;//指向下一条奖惩信息
}RP;

void show_all_rwinfo(RP* em_head);//显示所有在职人员奖惩记录
void show_rwinfo_by_id(RP *em_head,int id);
void show_rewardpunish(RP* prp);
int get_rewardpunish_count(RP* rp_head);
int delte_rewardpunish_by_id(RP* rp_head,int id);
#endif
