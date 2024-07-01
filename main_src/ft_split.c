/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 04:59:54 by mohmazou          #+#    #+#             */
/*   Updated: 2024/06/30 11:07:58 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	w_nmbr(char *map1d)
{
	int	i;
	int	cp_w;

	i = 0;
	cp_w = 0;
	while (map1d[i])
	{
		cp_w ++;
		i++;
		while (map1d[i] && map1d[i] != '\n')
			i ++;
	}
	return (cp_w);
}

char	*get_word(char *map1d, t_map *my_map)
{
	int		i;
	int		l;
	char	*word;

	l = 0;
	while (map1d[l] && map1d[l] != '\n')
		l ++;
	word = (char *)malloc(sizeof(char) * (l + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < l)
	{
		word[i] = map1d[i];
		i ++;
	}
	word[i] = '\0';
	my_map->size_x = i;
	return (word);
}

char	**split_words(char *map1d, char **map2d, t_map *my_map)
{
	int	i;

	i = 0;
	while (i < my_map->size_y)
	{
		if (*map1d == '\n')
			map1d ++;
		map2d[i] = get_word(map1d, my_map);
		if (!map2d)
		{
			while (i > 0 && map2d[i])
				free(map2d[--i]);
			if (map2d)
				free(map2d);
			return (0);
		}
		i ++;
		while (*map1d && *map1d != '\n')
			map1d ++;
	}
	map2d[i] = NULL;
	return (map2d);
}

char	**ft_split(char *map1d, t_map *my_map)
{
	int		len;
	char	**map2d;

	if (!map1d)
		return (NULL);
	len = w_nmbr(map1d);
	my_map->size_y = len;
	map2d = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map2d)
		return (NULL);
	map2d = split_words(map1d, map2d, my_map);
	return (map2d);
}
