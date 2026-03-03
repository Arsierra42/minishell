# **************************************************************************** #
#                                   Minishell                                  #
# **************************************************************************** #

NAME		:= minishell

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

# Paths
SRC_DIR		:= src
INC_DIR		:= includes
LIBFT_DIR	:= libft

# Auto-discover sources (all .c under src/)
SRCS		:= $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS		:= $(SRCS:.c=.o)

# Includes
INCLUDES	:= -I$(INC_DIR) -I$(LIBFT_DIR)

# Libft
LIBFT		:= $(LIBFT_DIR)/libft.a

# Readline (Linux / 42)
# If linking fails on your setup, see note below.
READLINE	:= -lreadline

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

run: $(NAME)
	./$(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re run valgrind
