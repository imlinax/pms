CFLAGS:=-g
OBJ:= pmsio.o employee.o menu.o pms.o rewardpunish.o init.o fileop.o
pms:$(OBJ) *.h
	gcc -o pms $(OBJ)
.PHONY:clean
clean:
	-rm *.o 
	-rm pms
