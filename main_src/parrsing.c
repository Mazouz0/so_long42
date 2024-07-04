/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:35:31 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/03 11:35:50 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	first_wall(char *map1d, int i)
{
	while (map1d[i] == '1')
		i++;
	if ((map1d[i] != '\n') || (map1d[i] == '\n' && i == 0))
		ft_error("Error : Invalid map");
	return (i);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->map2d[i]);
		i++;
	}
	free(map->map2d);
}

void	check_walls(char *map1d)
{
	int	i;

	i = first_wall(map1d, 0);
	while (map1d[i])
	{
		i++;
		if (map1d[i] != '1')
			ft_error("Error : Invalid map");
		while (map1d[i] != '\n' && map1d[i] != '\0')
			i++;
		if (map1d[i - 1] != '1')
			ft_error("Error : Invalid map");
	}
	i --;
	while (map1d[i] == '1')
		i--;
	if (map1d[i] != '\n')
		ft_error("Error : Invalid map");
}

void	check_duplication(char *map1d, t_map *my_map)
{
	int	i;
	int	cp_p;
	int	cp_e;
	int	cp_c;

	i = 0;
	cp_p = 0;
	cp_e = 0;
	cp_c = 0;
	while (map1d[i])
	{
		if (map1d[i] == 'P')
			cp_p++;
		if (map1d[i] == 'E')
			cp_e++;
		if (map1d[i] == 'C')
			cp_c++;
		i++;
	}
	if (cp_p != 1 || cp_e != 1 || cp_c < 1)
	{
		free(map1d);
		ft_error("Error : Invalid map");
	}
	my_map->coin = cp_c;
}

void	check_map(char *map1d, t_map *my_map)
{
	int	i;

	i = 0;
	while (map1d[i])
	{
		if ((map1d[i] != '1' && map1d[i] != '0' && map1d[i] != 'C'
			) && map1d[i] != 'E' && map1d[i] != 'P' && map1d[i] != '\n')
		{
			free(map1d);
			ft_error("Error : Invalid map character");
		}
		i++;
	}
	check_duplication(map1d, my_map);
	my_map->coin_counter = my_map->coin;
	check_walls(map1d);
}
