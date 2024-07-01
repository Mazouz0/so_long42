/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:50:11 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/30 12:03:34 by mohmazou         ###   ########.fr       */
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
	char	**map2d;
	int		coin;
	int		coin_counter;
	int		size_x;
	int		size_y;
	bool	exit;
	t_player	player_pos;
}	t_map;

typedef struct s_mlx
{
	mlx_t			*mlx_i;
	int				w_with;
	int 			w_height;
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
} t_mlx;

typedef struct s_game
{
	t_map	*my_map;
	t_mlx	*my_mlx;
}	t_game;

void	ft_putnbr(int n);
void	ft_error(void);
void	f_exit(void);
void	free_map(t_map *map);
void	exit_game(t_mlx *my_mlx);
void	render_game(t_mlx *my_mlx, t_map *my_map);
void	render_img(mlx_t *mlx_i, mlx_image_t *img, int x, int y);
void	read_map(char *path, t_map *my_map);
void	check_map(char *map1d, t_map *my_map);
char	**ft_split(char *map1d, t_map *my_map);
void	mlx_setup(t_mlx *my_mlx, t_map *my_map);
void	init_imgs(t_mlx *my_mlx);

#endif