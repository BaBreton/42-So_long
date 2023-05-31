SRC =	./srcs/errors.c \
		./srcs/events.c \
		./srcs/exit.c \
		./srcs/game_over.c \
		./srcs/images.c \
		./srcs/images_2.c \
		./srcs/initialization.c \
		./srcs/initialization_2.c \
		./srcs/map_format_1.c \
		./srcs/map_format_2.c \
		./srcs/map.c \
		./srcs/pathfinding.c \
		./srcs/so_long.c \
		./srcs/tiles.c \
		./srcs/traps.c \
		./srcs/utils_1.c \
		./srcs/utils_2.c \
		./includes/get_next_line.c \
		./includes/get_next_line_utils.c \
		./includes/printf/ft_printf.c
OBJS = $(SRC:.c=.o)
RM = rm -f
NAME = so_long
LMLX = ./includes/mlx/libmlx.a
LFT = ./includes/printf/libftprintf.a
LIB = -L ./includes/printf -lftprintf -L ./includes/mlx -lmlx -lXext -lX11 -lm -lbsd
all : ${LMLX} ${LFT} $(NAME)
${LMLX}:
		@make -s -C ./includes/mlx/ all
${LFT}:
		make -s -C ./includes/printf/ all
.c.o:
		@gcc -s -Wall -Werror -Wextra -g $(LIB) -c $< -o $(<:.c=.o)
$(NAME) :    $(OBJS)
		@gcc -s -Wall -Werror -Wextra -g ${OBJS} $(LIB) -o ${NAME}
		@echo "\033[32mDone !\033[0m"
clean :
		@$(RM) $(OBJS)
		@make -s -C ./includes/mlx/ clean
		@make -s -C ./includes/printf/ clean
fclean :    clean
			$(RM) $(NAME)
			make -C includes/printf/ fclean
re: fclean all
.PHONY: all clean fclean re