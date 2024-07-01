/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:06:03 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/30 12:10:02 by mohmazou         ###   ########.fr       */
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

void	render_img(mlx_t *mlx_i, mlx_image_t *img, int x, int y)
{
	int	res;
	
	res = mlx_image_to_window(mlx_i, img, x, y);
	if (res == -1)
	{
		write(1, "error rendering image\n", 22);
		exit(1);
	}
}

void	render_game(t_mlx *my_mlx, t_map *my_map)
{
	int x;
	int y;

	y = 0;
	while (y < my_map->size_y)
	{
		x = 0;
		while (x < my_map->size_x)
		{
			render_img(my_mlx->mlx_i, my_mlx->bg_img, x * GRADE, y * GRADE);
			if (my_map->map2d[y][x] == '1')
				render_img(my_mlx->mlx_i, my_mlx->wall_img, x * GRADE, y * GRADE);
			if (my_map->map2d[y][x] == 'C')
				render_img(my_mlx->mlx_i, my_mlx->coin_img, x * GRADE, y * GRADE);
			if (my_map->map2d[y][x] == 'E')
				render_img(my_mlx->mlx_i, my_mlx->exit_img, x * GRADE, y * GRADE);
			if (my_map->map2d[y][x] == 'P')
				render_img(my_mlx->mlx_i, my_mlx->player_img, x * GRADE, y * GRADE);
			x++;
		}
		y++;
	}
}