/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 05:40:57 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/04 04:40:29 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putnbr(int nbr)
{
	if (nbr < 10)
		write(1, &"0123456789"[nbr], 1);
	else
	{
		ft_putnbr(nbr / 10);
		write(1, &"0123456789"[nbr % 10], 1);
	}
}

void	update_img(t_game *game, int new_x, int new_y)
{
	int			old_x;
	int			old_y;
	static int	movse_cp;

	if (game->my_map->map2d[new_y][new_x] == 'C')
	{
		game->my_map->coin_counter--;
		render_img(game->my_mlx->mlx_i, game->my_mlx->bg_img,
			new_x * GRADE, new_y * GRADE);
	}
	old_x = game->my_map->player_pos.x;
	old_y = game->my_map->player_pos.y;
	game->my_map->map2d[old_y][old_x] = '0';
	game->my_map->map2d[new_y][new_x] = 'P';
	game->my_map->player_pos.x = new_x;
	game->my_map->player_pos.y = new_y;
	render_img(game->my_mlx->mlx_i, game->my_mlx->bg_img,
		old_x * GRADE, old_y * GRADE);
	render_img(game->my_mlx->mlx_i, game->my_mlx->player_img,
		new_x * GRADE, new_y * GRADE);
	write(1, "Movse: ", 7);
	ft_putnbr(++movse_cp);
	write(1, "\n", 1);
}

int	check_next(t_game *game, int next_x, int next_y)
{
	if ((game->my_map->map2d[next_y][next_x]
	) == 'E' && game->my_map->coin_counter == 0)
	{
		mlx_close_window(game->my_mlx->mlx_i);
		write(1, "Congrate You win !!!\n", 22);
	}
	if ((game->my_map->map2d[next_y][next_x] == '0'
	) || game->my_map->map2d[next_y][next_x] == 'C')
		return (1);
	return (0);
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
	if (key_data.key == UP && check_next(game, x, y - 1)
		&& (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
		update_img(game, x, y - 1);
	if (key_data.key == DOWN && check_next(game, x, y + 1)
		&& (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
		update_img(game, x, y + 1);
	if (key_data.key == LEFT && check_next(game, x - 1, y)
		&& (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
		update_img(game, x - 1, y);
	if (key_data.key == RIGHT && check_next(game, x + 1, y)
		&& (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT))
		update_img(game, x + 1, y);
}

void	mlx_setup(t_game *game)
{
	int		whidth;
	int		height;

	whidth = game->my_map->size_x * GRADE;
	height = game->my_map->size_y * GRADE;
	game->my_mlx->mlx_i = mlx_init(whidth, height, "so_long", false);
	if (!game->my_mlx->mlx_i)
		ft_error("mlx_init failed");
	init_imgs(game);
	render_game(game);
	mlx_key_hook(game->my_mlx->mlx_i, key_hook, game);
	mlx_loop(game->my_mlx->mlx_i);
}
