OBJ = screen.o test_screen.o comm.o sound.o
APPNAME = proggy

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl

%.o : &.c
	gcc -c -o $@ $<

clean:
	rm $(APPNAME) $(OBJ) 

zip:
	tar cf screen.tar *.c *.h makefile
