/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:34:14 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/30 23:41:43 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}


void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
	{
		if (map->map2d[i])
			free(map->map2d[i]);
		i++;
	}
}

void	f_exit(void)
{
	system("leaks so_long");
}

void flood_fill(t_map *map, int x, int y, char c)
{
	if ((map->map2d[y][x] == '1' || map->map2d[y][x] == 'x' || map->map2d[y][x] == 'E') && c == 'C')
		return ;
	if (map->map2d[y][x] == '1' && c == 'E')
		return ;
	if (map->map2d[y][x] == 'C' && c == 'C')
		map->coin_counter --;
	if (map->map2d[y][x] == 'E')
		map->exit = true;
	if (c == 'C')
		map->map2d[y][x] = 'x';
	if (c == 'E')
		map->map2d[y][x] = '1';
	flood_fill(map, x + 1, y, c);
	flood_fill(map, x - 1, y, c);
	flood_fill(map, x, y + 1, c);
	flood_fill(map, x, y - 1, c);
}


int	main(int ac, char **av)
{
	t_map	my_map;
	t_mlx	my_mlx;

	if (ac != 2)
	{
		write(1, "!! Usage : ./so_long map.ber\n", 29);
		exit(1);
	}
	read_map(av[1], &my_map);
	my_map.exit = false;
	flood_fill(&my_map, my_map.player_pos.x, my_map.player_pos.y, 'C');
	flood_fill(&my_map, my_map.player_pos.x, my_map.player_pos.y, 'E');
	if (my_map.coin_counter > 0 || my_map.exit == false)
		ft_error();
	free_map(&my_map);
	read_map(av[1], &my_map);
	mlx_setup(&my_mlx, &my_map);
}
