/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 03:35:23 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/01 02:50:16 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_dup(char *map1d, t_map *my_map)
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
			cp_p += 1;
		if (map1d[i] == 'E')
			cp_e += 1;
		if (map1d[i] == 'C')
			cp_c += 1;
		i ++;
	}
	if (cp_p != 1 || cp_e != 1 || cp_c <= 0)
		ft_error();
	my_map->coin_counter = cp_c;
}

int	first_wall(char *map1d, int i)
{
	while (map1d[i] == '1')
		i ++;
	if (map1d[i] != '\n' && i <= 1)
		ft_error();
	return (i);
}

void	check_walls(char *map1d)
{
	int	i;
	
	i = first_wall(map1d, 0);
	while (map1d[i])
	{
		i ++;
		if (map1d[i] != '1')
			ft_error();
		while (map1d[i] != '\n' && map1d[i] != '\0')
			i ++;
		if (map1d[i - 1] != '1')
			ft_error();
	}
	i --;
	while (map1d[i] == '1')
		i --;
	if (map1d[i] != '\n')
		ft_error();
}

void	check_map(char *map1d, t_map *my_map)
{
	int	i;

	i = 0;
	while (map1d[i])
	{
		if (map1d[i] != 'P' && map1d[i] != 'E' && map1d[i] != 'C'
			&& map1d[i] != '1' && map1d[i] != '0' && map1d[i] != '\n')
			ft_error();
		i ++;
	}
	check_dup(map1d, my_map);
	check_walls(map1d);
}
