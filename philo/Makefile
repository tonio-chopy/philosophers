NAME				=	philo

FILES				=	main.c \
						utils.c \
						parsing.c \
						init.c \
						life.c \
						watcher.c \

SRC_DIR				=	src
SRC					=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR				=	obj
OBJ					=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
INCLUDES			=	-I includes
DEBUGGER			=	-g3

all					:	$(NAME)


$(NAME)				:	$(OBJ_DIR) $(OBJ)
						$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
						@echo "philo compiled.\n"

$(OBJ_DIR)			:
						mkdir -p $@

$(OBJ_DIR)/%.o		:	$(SRC_DIR)/%.c
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean				:
						rm -rf $(OBJ_DIR)

fclean				:	clean
						rm -rf $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
