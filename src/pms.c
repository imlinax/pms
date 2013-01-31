#include <stdio.h>
#include "init.h"
#include "menu.h"

int main()
{
	GINFO *pginfo=NULL;
	pginfo=init_sys();
	menu(pginfo);
	return 0;
}
