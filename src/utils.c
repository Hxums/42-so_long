/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:55:11 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/28 22:48:20 by hcissoko         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	i;

	i = 0;
	while (i < n && s2[i] == s1[i] && s2[i] && s1[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
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

int	get_line_len(char *line)
{
	size_t	current_len;

	current_len = ft_strlen(line);
	if (line[current_len - 1] == '\n')
		current_len--;
	return (current_len);
}

void	empty_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
