OBJ:=employee.o menu.o pms.o rewardpunish.o
pms:$(OBJ) *.h
	gcc -o pms $(OBJ)
$(OBJ):$(@:.o=.c)
	gcc -o $@ -c $^
.PHONY:clean
clean:
	-rm *.o pms
