.PHONY: all link clean

LIB_NAME = SeGiN
CC = gcc
CC_FLAGS = -c -Wextra -O3
SRC_DIR = source
INC_DIR = include
LIB_DIR = lib
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, %.o, $(SRC))

all: link

%.o: $(SRC_DIR)/%.c
	@$(CC) $(CC_FLAGS) $^ -I$(INC_DIR)
	@echo $* compiled

link: $(OBJ)
	@ar rc $(LIB_DIR)/lib$(LIB_NAME) $(OBJ)
	@echo library linked

clean:
	@rm $(OBJ)
