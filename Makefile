all: compile create clean
compile:
	@gcc -c source/*.c -Iinclude
create:
	@ar rc lib/libSeGiN.a *.o
clean:
	@rm *.o