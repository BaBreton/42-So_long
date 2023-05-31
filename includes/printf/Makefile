

SRC = ft_printf.c ft_printf_utils.c

OBJS = $(SRC:.c=.o)

GCC = gcc -Wall -Werror -Wextra

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(GCC) -I ./c -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(NAME) $(OBJS)

re:
	@$(MAKE) -s fclean > /dev/null
	@$(MAKE) -s all > /dev/null


.PHONY: all clean fclean re
