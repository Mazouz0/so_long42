/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:03:42 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/04 03:45:30 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_img(mlx_t *mlx_i, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(mlx_i, img, x, y) == -1)
		ft_error("mlx_image_to_window failed");
}

void	render_game(t_game *game)
{
	int		x;
	int		y;
	t_mlx	*mlx;

	mlx = game->my_mlx;
	y = 0;
	while (y < game->my_map->size_y)
	{
		x = 0;
		while (x < game->my_map->size_x)
		{
			render_img(mlx->mlx_i, mlx->bg_img, x * GRADE, y * GRADE);
			if (game->my_map->map2d[y][x] == '1')
				render_img(mlx->mlx_i, mlx->wall_img, x * GRADE, y * GRADE);
			if (game->my_map->map2d[y][x] == 'C')
				render_img(mlx->mlx_i, mlx->coin_img, x * GRADE, y * GRADE);
			if (game->my_map->map2d[y][x] == 'E')
				render_img(mlx->mlx_i, mlx->exit_img, x * GRADE, y * GRADE);
			if (game->my_map->map2d[y][x] == 'P')
				render_img(mlx->mlx_i, mlx->player_img, x * GRADE, y * GRADE);
			x++;
		}
		y++;
	}
}
