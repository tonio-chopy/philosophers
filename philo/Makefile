NAME = philo
CC = cc
CFLAGS = -pthread -Wall -Werror -Wextra -g 

SRC_DIR = src
SRC_FILES = parsing/validate_args.c \
		utils/is_valid_number.c \
		utils/ft_atoi_error.c \
		utils/utils.c \
		init/init.c \
		init/cleanup.c \
		init/monitor.c \
		init/threads.c \
		philo_utils.c \
		philo_actions.c \
		philo_life.c \
		main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
    
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
    
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[37mClean done.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[37mFclean done.\033[0m"

re: fclean all

.PHONY: all clean fclean re
