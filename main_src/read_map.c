/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:00:18 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/03 11:38:06 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i >= 4 && path[--i] == 'r' && path[--i] == 'e'
		&& path[--i] == 'b' && path[--i] == '.')
		return ;
	ft_error("Error : Invalid map path");
}

char	*read_file(char *path)
{
	int		fd;
	int		i;
	char	*map1d;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error : Invalid map file");
	i = 0;
	while (read(fd, &buffer, 1) && i <= MAX_WIDTH * MAX_HEIGHT)
		i++;
	close(fd);
	if (!i)
		ft_error("Error : Empty map file");
	map1d = (char *)malloc(i + 1);
	if (!map1d)
		ft_error("Error : Malloc failed");
	fd = open(path, O_RDONLY);
	read(fd, map1d, i);
	map1d[i] = '\0';
	close(fd);
	return (map1d);
}

void	p_position(t_map *my_map)
{
	int	x;
	int	y;

	y = 0;
	while (my_map->map2d[y])
	{
		x = 0;
		while (my_map->map2d[y][x])
		{
			if (my_map->map2d[y][x] == 'P')
			{
				my_map->player_pos.x = x;
				my_map->player_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	read_map(char *path, t_map *my_map)
{
	char	*map1d;
	int		l_line;
	int		i;

	check_path(path);
	map1d = read_file(path);
	check_map(map1d, my_map);
	my_map->map2d = ft_split(map1d, my_map);
	if (!my_map->map2d)
		ft_error("Error : Malloc failed");
	i = 0;
	l_line = ft_strlen(my_map->map2d[i++]);
	my_map->size_x = l_line;
	while (my_map->map2d[i])
	{
		if (l_line != ft_strlen(my_map->map2d[i++]))
		{
			free(map1d);
			ft_free_map(my_map);
			ft_error("Error : Invalid map");
		}
	}
	p_position(my_map);
	free(map1d);
}
