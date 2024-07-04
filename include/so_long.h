/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:50:11 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/03 10:57:35 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42.h"

# define MAX_WIDTH 75
# define MAX_HEIGHT 75
# define GRADE 40
# define ESC MLX_KEY_ESCAPE
# define UP MLX_KEY_UP 
# define LEFT MLX_KEY_LEFT
# define DOWN MLX_KEY_DOWN
# define RIGHT MLX_KEY_RIGHT

typedef struct player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**map2d;
	int			coin;
	int			coin_counter;
	int			size_x;
	int			size_y;
	bool		exit;
	t_player	player_pos;
}	t_map;

typedef struct s_mlx
{
	mlx_t			*mlx_i;
	int				w_with;
	int				w_height;
	mlx_image_t		*player_img;
	mlx_image_t		*bg_img;
	mlx_image_t		*coin_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*exit_img;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*bg_texture;
	mlx_texture_t	*coin_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*exit_texture;
}					t_mlx;

typedef struct s_game
{
	t_map	*my_map;
	t_mlx	*my_mlx;
}	t_game;

void	ft_error(char *str);
void	ft_free_map(t_map *map);
int		ft_strlen(char *str);
void	flood_fill(t_map *map, int x, int y, char c);

void	check_path(char *path);
char	*read_file(char *path);
void	read_map(char *path, t_map *my_map);
void	p_position(t_map *my_map);

void	check_map(char *map1d, t_map *my_map);
void	check_duplication(char *map1d, t_map *my_map);
void	check_walls(char *map1d);
int		first_wall(char *map1d, int i);

char	**ft_split(char *map1d, t_map *my_map);
int		w_nmbr(char *map1d);
char	**split_words(char *map1d, char **map2d, int len);
char	*get_word(char *map1d);

void	ft_putnbr(int nbr);
void	update_img(t_game *game, int new_x, int new_y);
int		check_next(t_game *game, int next_x, int next_y);
void	key_hook(mlx_key_data_t key_data, void *param);
void	mlx_setup(t_game *game);

void	init_texture(t_game *game);
void	resize_img(t_game *game);
void	init_imgs(t_game *game);
void	exit_game(t_game *game);

void	render_img(mlx_t *mlx_i, mlx_image_t *img, int x, int y);
void	render_game(t_game *game);
#endif