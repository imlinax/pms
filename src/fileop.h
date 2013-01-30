#ifndef _FILEOP_H
#define _FILEOP_H

#include <stdio.h>
#include "global.h"
#include "employee.h"
GINFO	 *load_all(FILE *fp);//加载存在文件中的所有信息
EMPLOYEE *load_employees(FILE *fp,int count);//加载count个员工
RP	 *load_rewardpunish(FILE *fp,int count);//加载count条奖惩记录

int save_all(FILE *fp,GINFO* pginfo);//存储所有信息到文件中
int save_employees(FILE *fp,EMPLOYEE*);//存储所有员工信息到文件中
int save_rewardpunish(FILE *fp,RP*);//存储所有奖惩记录
#endif
