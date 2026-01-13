/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:55:11 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/13 08:21:57 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strsfree(char **strs, int i)
{
	while (0 < i)
	{
		i--;
		free(strs[i]);
	}
	free(strs);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_pos	get_player_pos(t_map *map)
{
	int		i;
	int		j;
	t_pos	position;

	i = -1;
	position.height = -1;
	position.width = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				position.height = i;
				position.width = j;
				return (position);
			}
		}
	}
	return (position);
}
