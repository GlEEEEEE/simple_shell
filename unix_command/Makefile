# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Source files
SRC = main.c read_input.c parse_input.c execute.c free_args.c get_env.c get_cmd_path.c

# Object files
OBJ = $(SRC:.c=.o)

# Header files
HEADER = shell.h

# Executable file
TARGET = hsh

# Default rule to build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Rule to build object files from source files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# .PHONY rule to avoid conflicts with files named 'clean' and 'all'
.PHONY: clean all

