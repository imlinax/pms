#ifndef _REWARDPUNISH_H
#define _REWARDPUNISH_H

#ifndef _RPFLAG
#define _RPFLAG
#endif

#define RP_SAVE_SIZE (sizeof(RP))	//保存到文件时丢弃next指针

typedef struct reward_punish
{
	int id;//工号
	#ifdef _RPFLAG 
	int rpflag;
	#endif
	int money;//奖惩多少钱,正数为奖,负数为惩
	char data;//日期
	char description[128];//描述
	struct reward_punish* next;//指向下一条奖惩信息
}RP;

#endif
