/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 06:06:45 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/03 11:23:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_texture(t_game *game)
{
	game->my_mlx->player_texture = mlx_load_png("textures/player.png");
	game->my_mlx->bg_texture = mlx_load_png("textures/back_ground.png");
	game->my_mlx->coin_texture = mlx_load_png("textures/coin.png");
	game->my_mlx->wall_texture = mlx_load_png("textures/wall.png");
	game->my_mlx->exit_texture = mlx_load_png("textures/portal.png");
	if ((!game->my_mlx->player_texture || !game->my_mlx->bg_texture
		) || (!game->my_mlx->coin_texture || !game->my_mlx->wall_texture
		) || !game->my_mlx->exit_texture)
	{
		if (game->my_mlx->player_texture)
			mlx_delete_texture(game->my_mlx->player_texture);
		if (game->my_mlx->bg_texture)
			mlx_delete_texture(game->my_mlx->bg_texture);
		if (game->my_mlx->coin_texture)
			mlx_delete_texture(game->my_mlx->coin_texture);
		if (game->my_mlx->wall_texture)
			mlx_delete_texture(game->my_mlx->wall_texture);
		if (game->my_mlx->exit_texture)
			mlx_delete_texture(game->my_mlx->exit_texture);
		ft_error("mlx_load_png failed");
	}
}

void	exit_game(t_game *game)
{
	mlx_delete_texture(game->my_mlx->player_texture);
	mlx_delete_texture(game->my_mlx->bg_texture);
	mlx_delete_texture(game->my_mlx->coin_texture);
	mlx_delete_texture(game->my_mlx->wall_texture);
	mlx_delete_texture(game->my_mlx->exit_texture);
	mlx_delete_image(game->my_mlx->mlx_i, game->my_mlx->player_img);
	mlx_delete_image(game->my_mlx->mlx_i, game->my_mlx->bg_img);
	mlx_delete_image(game->my_mlx->mlx_i, game->my_mlx->coin_img);
	mlx_delete_image(game->my_mlx->mlx_i, game->my_mlx->wall_img);
	mlx_delete_image(game->my_mlx->mlx_i, game->my_mlx->exit_img);
	mlx_terminate(game->my_mlx->mlx_i);
	ft_free_map(game->my_map);
}

void	resize_img(t_game *game)
{
	if (!mlx_resize_image
		(game->my_mlx->player_img, GRADE, GRADE) || !mlx_resize_image
		(game->my_mlx->bg_img, GRADE, GRADE) || !mlx_resize_image
		(game->my_mlx->coin_img, GRADE, GRADE) || !mlx_resize_image
		(game->my_mlx->wall_img, GRADE, GRADE) || !mlx_resize_image
		(game->my_mlx->exit_img, GRADE, GRADE))
		ft_error("mlx_resize_image failed");
}

void	init_imgs(t_game *game)
{
	mlx_t	*mlx_i;
	t_mlx	*my_mlx;

	mlx_i = game->my_mlx->mlx_i;
	my_mlx = game->my_mlx;
	init_texture(game);
	my_mlx->player_img = mlx_texture_to_image(mlx_i, my_mlx->player_texture);
	my_mlx->bg_img = mlx_texture_to_image(mlx_i, my_mlx->bg_texture);
	my_mlx->coin_img = mlx_texture_to_image(mlx_i, my_mlx->coin_texture);
	my_mlx->wall_img = mlx_texture_to_image(mlx_i, my_mlx->wall_texture);
	my_mlx->exit_img = mlx_texture_to_image(mlx_i, my_mlx->exit_texture);
	resize_img(game);
}
