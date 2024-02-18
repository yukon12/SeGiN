.PHONY: all link run clean

EXE_NAME = prog
CC = gcc
CC_FLAGS = -c -Wextra
SRC_DIR = .
INC_DIR = ../include
LIB_DIR = ../lib
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
LIBS = -lSeGiN

all: link run

%.o: %.c
	@$(CC) $(CC_FLAGS) $^ -I$(INC_DIR)
	@echo $* compiled

link: $(OBJ)
	@$(CC) -o $(EXE_NAME) $(OBJ) -L$(LIB_DIR) $(LIBS)
	@echo executable linked

run:
	@./prog

clean:
	@rm $(OBJ)
