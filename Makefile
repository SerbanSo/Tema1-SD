efile = tema1
ofile = main.o list.o task1.o task2.o task3.o task4.o bonus.o

build: $(ofile)
	gcc -Wall $(ofile) -o $(efile) -lm
$@.o: $@.c $@.h
	gcc -c $@.c
run: $(efile)
	./$(efile)
clean: 
	rm -f $(efile) $(ofile)
