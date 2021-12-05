# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rutgercappendijk <rutgercappendijk@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 13:39:03 by rcappend      #+#    #+#                  #
#    Updated: 2021/11/03 12:45:24 by rcappend      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS		=	main.c \
				./utils/ft_strchr.c ./utils/ft_strlen.c ./utils/ft_atoi.c \
				./utils/ft_strncmp.c ./utils/ft_substr.c ./utils/ft_isdigit.c \
				./utils/ft_calloc.c ./utils/ft_isspace.c ./utils/ft_memcpy.c \
				./utils/ft_bzero.c ./utils/create_trgb.c ./utils/ft_strcpy.c \
				./utils/ft_memset.c ./utils/ft_strtrim.c \
				./gnl/get_next_line_utils.c ./gnl/get_next_line.c \
				./config/read_config.c ./config/file_parser.c \
				./config/check_map.c ./config/config_utils.c \
				./config/make_map.c ./config/load_textures.c \
				./config/start_pos.c \
				./engine/init.c ./engine/draw_utils.c \
				./engine/render_next_frame.c ./engine/key_hooks.c \
				./engine/raycasting.c ./engine/draw_room.c \
				./engine/draw_sprites.c ./engine/calc_sprite.c \
				./engine/sprite_utils.c
OBJS		=	$(SRCS:.c=.o)

LIBS		=	-L. -lmlx -framework OpenGL -framework AppKit -lm

MLX			=	libmlx.dylib

CC			=	gcc

CFLAGS		= 	-Wall -Werror -Wextra -g3

all:		$(NAME)
$(NAME):	$(MLX) $(OBJS)
			$(CC) ${CFLAGS} ${LIBS} ${OBJS}  -o ${NAME}

$(MLX):
	@$(MAKE) -C mlx
	mv mlx/$(MLX) .

run: all
	./$(NAME) maps/test2.cub

drun: all
	lldb $(NAME) -- maps/test2.cub

clean:
	@$(MAKE) -C mlx clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(MLX)

re:	fclean all

phony:
	all clean fclean re libft