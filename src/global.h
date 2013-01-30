#ifndef _GLOBAL_H
#define _GLOBAL_H
#include "employee.h"
#include "rewardpunish.h"
typedef struct global_info
{
	int em_count;//保存所有员工数
	int rp_count;//保存奖惩记录数
	EMPLOYEE *em_head;//	
	RP	 *rp_head;

}GINFO;

#endif
