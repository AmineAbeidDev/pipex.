CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRC = pipex.c pipex_gear/multi_ops_executer.c utils/ft_split.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c gnl/get_next_line_utils.c\
	utils/ft_strtrim.c pipex_gear/executer.c gnl/get_next_line.c \
	pipex_gear/path_getter_finder.c	utils/ft_strnstr.c pipex_gear/errors_handler.c \
	utils/ft_strchr.c

B_SRC = pipex_bonus.c pipex_gear/multi_ops_executer.c utils/ft_split.c \
	utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c gnl/get_next_line_utils.c\
	utils/ft_strtrim.c pipex_gear/executer.c gnl/get_next_line.c \
	pipex_gear/path_getter_finder.c	utils/ft_strnstr.c pipex_gear/errors_handler.c \
	utils/ft_strchr.c

OBJ = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ) $(B_OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
bonus: $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME)