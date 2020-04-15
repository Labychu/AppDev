OBJ = screen.o test_screen.o
APPNAME = proggy

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : &.c
	gcc -c -o $@ $<

clean:
	rm $(APPNAME) $(OBJ) 

zip:
	tar cf screen.tar *.c *.h makefile
