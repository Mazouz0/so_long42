/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:12:54 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/01 03:12:14 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_mlx *my_mlx, t_map *my_map)
{
	if (my_map->map2d)
		free_map(my_map);
	if (my_mlx)
		exit_game(my_mlx); //tanrja3 
}

int	check_next(t_game *game, int next_x, int next_y)
{
	if (game->my_map->map2d[next_y][next_x] == 'E' && game->my_map->coin_counter == 0)
		mlx_close_window(game->my_mlx->mlx_i);
	if (game->my_map->map2d[next_y][next_x] == '0' || game->my_map->map2d[next_y][next_x] == 'C')
	{
		if (game->my_map->map2d[next_y][next_x] == 'C')
			game->my_map->coin_counter --;
		return (1);
	}
	return (0);
}

void	update(t_game *game, int new_x, int new_y)
{
	int		x;
	int		y;
	static int moves;

	x = game->my_map->player_pos.x;
	y = game->my_map->player_pos.y;
	game->my_map->map2d[y][x] = '0';
	game->my_map->map2d[new_y][new_x] = 'P';
	game->my_map->player_pos.x = new_x;
	game->my_map->player_pos.y = new_y;
	render_img(game->my_mlx->mlx_i, game->my_mlx->bg_img, x * GRADE, y * GRADE);
	render_img(game->my_mlx->mlx_i, game->my_mlx->bg_img, new_x * GRADE, new_y * GRADE);
	render_img(game->my_mlx->mlx_i, game->my_mlx->player_img, new_x * GRADE, new_y * GRADE);
	ft_putnbr(++moves);
	write(1, "\n", 1);
}

void	key_hook(mlx_key_data_t key_data, void *param)
{
	t_game	*game;
	int		x;
	int		y;
	
	game = (t_game *)param;
	x = game->my_map->player_pos.x;
	y = game->my_map->player_pos.y;
	if (key_data.key == ESC)
		mlx_close_window(game->my_mlx->mlx_i);
	if (key_data.key == UP && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT) 
		&& check_next(game, x, y - 1))
		update(game, x, y - 1);
	if (key_data.key == DOWN && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
		&& check_next(game, x, y + 1))
		update(game, x, y + 1);
	if (key_data.key == LEFT && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
		&& check_next(game, x - 1, y))
		update(game, x - 1, y);
	if (key_data.key == RIGHT && (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT)
		&& check_next(game, x + 1, y))
		update(game, x + 1, y);
}

void	mlx_setup(t_mlx *my_mlx, t_map *my_map)
{
	t_game	game;
	int		whidth;
	int 	height;

	atexit(f_exit);
	whidth = my_map->size_x * GRADE;
	height = my_map->size_y * GRADE;
	game.my_map = my_map;
	game.my_mlx = my_mlx;
	game.my_mlx->mlx_i = mlx_init(whidth, height, "so_long", false);
	if (!my_mlx->mlx_i)
		write(1, "mlx_init not success\n", 22);
	init_imgs(my_mlx);
	render_game(my_mlx, my_map);
	mlx_key_hook(my_mlx->mlx_i, key_hook, &game);
	
	mlx_loop(my_mlx->mlx_i);
	free_game(my_mlx, my_map);
	if (my_mlx->mlx_i)
		mlx_terminate(my_mlx->mlx_i); // dooble free here
}