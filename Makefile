SRC = $(wildcard src/*.c)
OBJ = ${SRC:.c=.o}
LIB = $(PWD)/include
TEST_DIR = $(wildcard test/*.c)
HON_lib = $(wildcard src/HatONames.c)
OUT = app
TST = tests

# Fallback to gcc if clang not available
CC = clang
clang = $(shell which clang 2> /dev/null)
ifeq (, $(clang))
	CC = gcc
endif

$(OUT): $(OBJ)
	@$(CC) $^ -o $@
	@printf "\e[34mDone!\e[0m\n"

%.o: %.c
	@$(CC) -c $< -o $@
	@printf "\e[36mCompile\e[90m %s\e[0m\n" $@

clean:
	@rm -f $(OUT) $(OBJ)
	@printf "\e[34mApp build clear!\e[0m\n"
	@rm -f $(TST) 
	@printf "\e[34mTest build clear!\e[0m\n"

tests: $(TEST_DIR) $(HON_lib)
	make $(OUT)
	@$(CC) $^ -o $@ -L$(LIB) -lunity
	@printf "\e[36mCompile\e[90m %s\e[0m\n" $@

