OBJ = screen.o main.o comm.o sound.o
APPNAME = proggy

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl -lm

%.o : &.c
	gcc -c -o $@ $<

run:
	./proggy

clean:
	rm $(APPNAME) $(OBJ) 

zip:
	tar cf sound.tar *.c *.h makefile
