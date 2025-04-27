# # Library Name
LIB_NAME := libft.a

# Directories
SRC_DIRS := src/ft_is src/ft_mem src/ft_put src/ft_to src/ft_str src/ft_lst src/ft_printf src/get_next_line
OBJ_DIR := obj
INC_DIR := inc

# Compiler and Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INC_DIR)
AR := ar rcs
RM := rm -rf

# Collect all source files recursively
SRC := $(shell find $(SRC_DIRS) -type f -name "*.c")
OBJ := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Default Target
all: $(LIB_NAME)

# Create Library
$(LIB_NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "Libft compiled successfully!"

# Compile Object Files
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure Object Directory Exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Cleaning Rules
clean:
	@$(RM) $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(LIB_NAME)
	@echo "Fully cleaned: Removed $(LIB_NAME)"

# Recompile Everything
re: fclean all

.PHONY: all clean fclean re
