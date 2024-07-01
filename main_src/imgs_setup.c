/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:53:47 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/30 11:16:12 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_tex(t_mlx *my_mlx)
{
	my_mlx->player_texture = mlx_load_png("textur/player.png");
	my_mlx->bg_texture = mlx_load_png("textur/back_ground.png");
	my_mlx->coin_texture = mlx_load_png("textur/coin.png");
	my_mlx->wall_texture = mlx_load_png("textur/wall.png");
	my_mlx->exit_texture = mlx_load_png("textur/portal.png");
	if (!my_mlx->player_texture || !my_mlx->bg_texture || !my_mlx->coin_texture || !my_mlx->wall_texture || !my_mlx->exit_texture)
	{
		if (my_mlx->player_texture)
			mlx_delete_texture(my_mlx->player_texture);
		if (my_mlx->bg_texture)
			mlx_delete_texture(my_mlx->bg_texture);
		if (my_mlx->coin_texture)
			mlx_delete_texture(my_mlx->coin_texture);
		if (my_mlx->wall_texture)
			mlx_delete_texture(my_mlx->wall_texture);
		if (my_mlx->exit_texture)
			mlx_delete_texture(my_mlx->exit_texture);
		write(1, "texture error loading !!", 24);
		exit(1);
	}
	write(1, "texture loaded succeful\n", 24);
}

void	exit_game(t_mlx *my_mlx)
{
	if (my_mlx->player_img)
		mlx_delete_image(my_mlx->mlx_i, my_mlx->player_img);
	if (my_mlx->bg_img)
		mlx_delete_image(my_mlx->mlx_i, my_mlx->bg_img);
	if (my_mlx->coin_img)
		mlx_delete_image(my_mlx->mlx_i, my_mlx->coin_img);
	if (my_mlx->wall_img)
		mlx_delete_image(my_mlx->mlx_i, my_mlx->wall_img);
	if (my_mlx->exit_img)
		mlx_delete_image(my_mlx->mlx_i, my_mlx->exit_img);
	if (my_mlx->player_texture)
		mlx_delete_texture(my_mlx->player_texture);
	if (my_mlx->bg_texture)
		mlx_delete_texture(my_mlx->bg_texture);
	if (my_mlx->coin_texture)
		mlx_delete_texture(my_mlx->coin_texture);
	if (my_mlx->wall_texture)
		mlx_delete_texture(my_mlx->wall_texture);
	if (my_mlx->exit_texture)
		mlx_delete_texture(my_mlx->exit_texture);
	if (my_mlx->mlx_i)
		mlx_terminate(my_mlx->mlx_i);
	mlx_close_window(my_mlx->mlx_i);
}

void	resize_imgs(t_mlx *my_mlx)
{
	if (!mlx_resize_image(my_mlx->player_img, GRADE, GRADE))
		exit_game(my_mlx);
	if (!mlx_resize_image(my_mlx->bg_img, GRADE, GRADE))
		exit_game(my_mlx);
	if (!mlx_resize_image(my_mlx->coin_img, GRADE, GRADE))
		exit_game(my_mlx);
	if (!mlx_resize_image(my_mlx->wall_img, GRADE, GRADE))
		exit_game(my_mlx);
	if (!mlx_resize_image(my_mlx->exit_img, GRADE, GRADE))	
		exit_game(my_mlx);
	write(1, "image resized succeful\n", 24);
}

void	init_imgs(t_mlx *my_mlx)
{
	init_tex(my_mlx);
	my_mlx->player_img = mlx_texture_to_image(my_mlx->mlx_i, my_mlx->player_texture);
	my_mlx->bg_img = mlx_texture_to_image(my_mlx->mlx_i, my_mlx->bg_texture);
	my_mlx->coin_img = mlx_texture_to_image(my_mlx->mlx_i, my_mlx->coin_texture);
	my_mlx->wall_img = mlx_texture_to_image(my_mlx->mlx_i, my_mlx->wall_texture);
	my_mlx->exit_img = mlx_texture_to_image(my_mlx->mlx_i, my_mlx->exit_texture);
	write(1, "image loaded succeful\n", 22);
	resize_imgs(my_mlx);
}
