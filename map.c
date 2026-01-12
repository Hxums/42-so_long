/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:12:07 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/12 12:01:24 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (line)
	{
		map->height = 0;
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		map->width = len;
		while (line)
		{
			map->height++;
			free(line);
			line = get_next_line(fd);
		}
	}
	close(fd);
}

void	free_map_grid(t_map *map, int i)
{
	while (i > -1)
	{
		free(map->grid[i]);
		i--;
	}
	free(map->grid);
}

int	fill_map(int fd, t_map *map)
{
	int	i;
	int	len;

	len = map->width;
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i])
		{
			free_map_grid(map, i - 1);
			return (0);
		}
		if (map->grid[i][len - 1] == '\n')
			map->grid[i][len - 1] = 0;
		i++;
	}
	return (1);
}

t_map	*failed_map(t_map *map)
{
	free(map);
	return (NULL);
}

t_map	*gen_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->collectible = 0;
	set_map_size(filename, map);
	if (map->height == 0 || map->width == 0)
		return (failed_map(map));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (failed_map(map));
	map->grid = malloc(sizeof(char *) * (map->height));
	if (!map->grid ||!fill_map(fd, map))
	{
		close(fd);
		return (failed_map(map));
	}
	close(fd);
	return (map);
}
