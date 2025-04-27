# Program Name
TARGET := push_swap

# Directories
LIBFT := ./libft/libft.a
INC := inc
SRC_DIR := srcs
OBJ_DIR := obj

# Compiler Settings
CC := cc
CFLAGS := -Wall -Werror -Wextra -g -I$(INC)
RM := rm -f

# Source Files
SRC := \
    $(wildcard $(SRC_DIR)/commands/*.c) \
    $(wildcard $(SRC_DIR)/push_swap/*.c)

# Object Files
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build Rules
all: $(LIBFT) $(TARGET)

$(LIBFT):
	@make -C libft

$(TARGET): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(TARGET)
	@echo "Compilation successful!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/commands $(OBJ_DIR)/push_swap

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C libft
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(TARGET)
	@make fclean -C libft
	@echo "Removed executable and library"

re: fclean all

.PHONY: all clean fclean re
