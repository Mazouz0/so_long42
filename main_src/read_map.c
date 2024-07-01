/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:57:22 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/01 02:56:22 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*read_file(char *path)
{
	int		fd;
	int		i;
	char	*map1d;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error();
	i = 0;
	while (read(fd, &buffer, 1) == 1 && i <= MAX_WIDTH * MAX_HEIGHT)
		i ++;
	close(fd);
	if (!i)
		ft_error();
	map1d = (char *)malloc((i + 1) * sizeof(char));
	if (!map1d)
	{
		write(1, "Error allocation !!\n", 20);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	read(fd, map1d, i);
	map1d[i] = '\0';
	return (close(fd), map1d);
}

void	check_path(char *path)
{
	int		i;

	i = 0;
	while (path[i])
		i ++;
	if (i >= 4 && path[--i] == 'r' && path[--i] == 'e'
		&& path[--i] == 'b' && path[--i] == '.')
		return ;
	else
		ft_error();
}

int	ft_strline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i ++;
	return (i);
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
			x ++;
		}
		y ++;
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
	my_map->coin = my_map->coin_counter;
	my_map->map2d = ft_split(map1d, my_map);
	if (!my_map->map2d)
	{
		write(1, "Error allocation !!\n", 20);
		exit(1);
	}
	i = 0;
	l_line = ft_strline(my_map->map2d[i  ++]);
	while (my_map->map2d[i])
		if (l_line != ft_strline(my_map->map2d[i++]) || map1d[0] == '\n')
			ft_error();
	p_position(my_map);
	if (map1d)
		free(map1d);
}
