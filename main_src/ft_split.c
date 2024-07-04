/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:10:56 by mohmazou          #+#    #+#             */
/*   Updated: 2024/07/03 10:59:01 by mohmazou         ###   ########.fr       */
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
		cp_w++;
		i++;
		while (map1d[i] != '\n' && map1d[i])
			i++;
	}
	return (cp_w);
}

char	*get_word(char *map1d)
{
	int		i;
	char	*word;

	i = 0;
	while (map1d[i] != '\n' && map1d[i])
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
	{
		free(map1d);
		ft_error("Error : Malloc failed");
	}
	i = 0;
	while (map1d[i] != '\n' && map1d[i])
	{
		word[i] = map1d[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_words(char *map1d, char **map2d, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (*map1d == '\n')
			map1d++;
		map2d[i] = get_word(map1d);
		if (!map2d[i])
		{
			while (i >= 0)
				free(map2d[i--]);
			free(map2d);
			free(map1d);
			ft_error("Error : Malloc failed");
		}
		i ++;
		while (*map1d != '\n' && *map1d)
			map1d++;
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
	{
		free(map1d);
		ft_error("Error : Malloc failed");
	}
	map2d = split_words(map1d, map2d, len);
	return (map2d);
}
