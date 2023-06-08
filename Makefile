# SRCS folder
SRCS	+=			srcs/main.c \
					srcs/init.c \
					srcs/update.c \
					srcs/close.c
# KEY folder
SRCS	+=			srcs/key/keys_init.c \
					srcs/key/on_keypressed.c \
					srcs/key/on_keyreleased.c
# draw folder
SRCS	+=			srcs/draw/draw_rect.c \
					srcs/draw/draw_background.c

# utils folder
SRCS	+=			srcs/utils/time_utils.c

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w

NAME	=			cube3d

all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -Iincls -Ilibft -I./minilibx -c $? -o $@

${NAME}:			${OBJS}
					@make -C libft
					@make -C minilibx
					${CC} ${CFLAGS} $^ -Llibft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

# libft/libft.a:
# 					@make -C libft

# minilibx/libmlx.a:
# 					@make -C minilibx

clean:
					${RM} $(OBJS)
					@make -C libft clean
					@make -C minilibx clean

fclean:				clean
					${RM} $(NAME)
					@make -C libft fclean
					@make -C minilibx fclean

re: 				fclean all

.PHONY:				all  clean fclean re
