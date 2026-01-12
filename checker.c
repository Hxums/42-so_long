/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:12:30 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/12 15:52:28 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	filename_is_correct(char *str)
{
	int		size;
	int		i;
	t_map	map;

	size = ft_strlen(str);
	i = 0;
	if (size < 5)
		return (0);
	while (EXTENSION[i] && str[size - ft_strlen(EXTENSION) + i])
	{
		if (EXTENSION[i] != str[size - ft_strlen(EXTENSION) + i])
			return (0);
		i++;
	}
	return (EXTENSION[i] == str[size - ft_strlen(EXTENSION) + i]);
}

int	is_rectangle(int fd)
{
	char	*line;
	size_t	line_len;
	size_t	current_len;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 1;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	while (line)
	{
		current_len = ft_strlen(line);
		if (line[current_len - 1] == '\n')
			current_len--;
		if (line_len != current_len)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i > 1);
}

int	map_surrounded_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_is_valid(t_map *map)
{
	int	i;
	int	j;
	int	exit;
	int	start;

	i = -1;
	exit = 0;
	start = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'C')
				map->collectible++;
			else if (map->grid[i][j] == 'E')
				exit++;
			else if (map->grid[i][j] == 'P')
				start++;
			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1')
				return (0);
		}
	}
	return (start == 1 && exit == 1 && map->collectible > 0);
}



int	map_can_be_done(t_map *map)
{
	return (0);
}