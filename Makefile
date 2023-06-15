# --------------- source files --------------- #
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
SRCS	+=			srcs/draw/color.c \
					srcs/draw/draw_pixel.c \
					srcs/draw/draw_rect.c \
					srcs/draw/draw_background.c \
					srcs/draw/line/draw_line.c \

# utils folder
SRCS	+=			srcs/utils/time_utils.c \
					srcs/utils/update_utils.c

# parser folder
SRCS	+=			srcs/parsing/parser.c \
					srcs/parsing/create_map.c

# ---------------  --------------- #

NAME	=			cub3d

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS	=	-Llibft -lft -L./minilibx/linux -lmlx -lXext -lX11 -lm -lbsd
	MLX_DIR = minilibx/linux
else
	LIBS = -Llibft -lft -L./minilibx/mac -lmlx -framework OpenGL -framework AppKit
	MLX_DIR = minilibx/mac
endif


all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -Iincls -Ilibft -I${MLX_DIR} -c $? -o $@

${NAME}:			${OBJS}
					@make -C libft
					@make -C ${MLX_DIR}
					${CC} ${CFLAGS} $^ ${LIBS} -o ${NAME}

clean:
					${RM} $(OBJS)
					@make -C libft clean
					@make -C ${MLX_DIR} clean

name:
					@echo $(MLX_DIR)

fclean:				clean
					${RM} $(NAME)
					@make -C libft fclean
#					@make -C minilibx fclean # currently don't on linux

re: 				fclean all

.PHONY:				all  clean fclean re
