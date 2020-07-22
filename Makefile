NAME = fillit

CFLAGS += -Wall -Wextra -Werror

SRC = srcs/get_next_line.c\
      srcs/backtrcking.c\
      srcs/fitting.c\
      srcs/func.c\
      srcs/list.c\
      srcs/main.c\
      srcs/clear.c\
      srcs/validation.c\
      srcs/ft_putstr.c\
      srcs/ft_strchr.c\
      srcs/ft_strdel.c\
      srcs/ft_strdup.c\
      srcs/ft_strjoin.c\
      srcs/ft_strsub.c\
      srcs/ft_strlen.c\
      srcs/ft_putchar.c\


OBJ = $(SRC:.c=.o)

INC_DIR = ./includes

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME):  $(OBJ) $(INC_DIR)
	@gcc $(OBJ)  -I includes/fillit.h -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean clean re