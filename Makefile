# --------------- source files --------------- #
# srcs folder
SRCS	+=			srcs/main.c \
					srcs/init.c \
					srcs/update.c \

# close folder
SRCS	+=			srcs/close/close.c \
					srcs/close/free_split.c \ # where to put that ?

# key folder
SRCS	+=			srcs/key/keys_init.c \
					srcs/key/on_keypressed.c \
					srcs/key/on_keyreleased.c \
					srcs/key/on_mousepressed.c \
					srcs/key/on_mouserelease.c


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
					srcs/parsing/parse_map.c \
					srcs/parsing/parse_color.c \
					srcs/parsing/parse_textures.c \
					srcs/parsing/get_next_unempty_line.c \
					# srcs/parsing/get_map_size.c \
					# srcs/parsing/parse_textures_and_colors.c

# minimap folder
SRCS	+=			srcs/minimap/minimap.c \
					srcs/minimap/init_settings.c \
					srcs/minimap/raycasting.c \
					srcs/minimap/raycasting_utils.c \

# player folder
SRCS	+=			srcs/player/player.c \
					srcs/player/collisions.c \

# ---------------  --------------- #

NAME	=			cub3d

OBJS	=			$(SRCS:%.c=%.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -w -O2 -fsanitize=address

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
