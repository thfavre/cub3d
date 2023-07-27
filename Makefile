# --------------- source files --------------- #
# srcs folder
SRCS	+=			srcs/main.c \
					srcs/init.c \
					srcs/update.c

# settings folder
SRCS	+=			srcs/settings/settings.c \
					srcs/settings/settings_check_boxes.c \
					srcs/settings/settings_sliders.c \

# close folder
SRCS	+=			srcs/close/close.c \
					srcs/close/free_split.c

# key folder
SRCS	+=			srcs/key/keys_init.c \
					srcs/key/on_keypressed.c \
					srcs/key/on_keyreleased.c \
					srcs/key/on_mousepressed.c \
					srcs/key/on_mouserelease.c \


# draw folder
SRCS	+=			srcs/draw/color.c \
					srcs/draw/draw_pixel.c \
					srcs/draw/draw_rect.c \
					srcs/draw/line/draw_line.c \
					srcs/draw/gui/collide_point.c \
					srcs/draw/gui/slider.c \
					srcs/draw/gui/check_box.c

# time folder
SRCS	+=			srcs/time/_time.c \

# parser folder
SRCS	+=			srcs/parsing/parser.c \
					srcs/parsing/parse_map.c \
					srcs/parsing/parse_color.c \
					srcs/parsing/parse_textures.c \
					srcs/parsing/get_next_unempty_line.c

# minimap folder
SRCS	+=			srcs/minimap/minimap.c \
					srcs/minimap/init_settings.c \
					srcs/minimap/raycasting.c \
					srcs/minimap/raycasting_utils.c

# player folder
SRCS	+=			srcs/player/player.c \
					srcs/player/collisions.c

# ---------------  --------------- #

NAME	=			cub3D

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w -O2 #-fsanitize=address

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

re: 				fclean all

.PHONY:				all  clean fclean re
