NAME		= so_long

CC			= cc

CFLAGS		= -Wextra -Wall -Werror -Ofast

MLX_FLAGS	= lib/libmlx42.a lib/libglfw3.a -framework \
			Cocoa -framework OpenGL -framework IOKit

SRC			= main_src/so_long.c main_src/read_map.c main_src/parrsing.c main_src/ft_split.c \
			main_src/mlx_setup.c main_src/imgs_setup.c main_src/game_render.c \

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

%.o: %.c include/MLX42/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
