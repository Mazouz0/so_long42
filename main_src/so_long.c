/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 05:53:49 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/04 09:59:42 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	flood_fill(t_map *map, int x, int y, char c)
{
	if (c == 'C' && (map->map2d[y][x] == '1'
		|| map->map2d[y][x] == 'E' || map->map2d[y][x] == 'x'))
		return ;
	if (c == 'E' && map->map2d[y][x] == '1')
		return ;
	if (c == 'C' && map->map2d[y][x] == 'C')
		map->coin_counter--;
	if (c == 'E' && map->map2d[y][x] == 'E')
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
	t_map	map;
	t_mlx	mlx;
	t_game	game;

	game.my_map = &map;
	game.my_mlx = &mlx;
	if (ac != 2)
		ft_error("Usage Error : .so_long [map].ber !!");
	read_map(av[1], &map);
	map.exit = false;
	flood_fill(&map, map.player_pos.x, map.player_pos.y, 'C');
	flood_fill(&map, map.player_pos.x, map.player_pos.y, 'E');
	if (map.coin_counter != 0 || map.exit == false)
		ft_error("Map Error : Invalid Map");
	ft_free_map(&map);
	read_map(av[1], &map);
	if (map.size_y > 30 || map.size_x > 50)
		ft_error("Map size is too big");
	mlx_setup(&game);
	exit_game(&game);
}
