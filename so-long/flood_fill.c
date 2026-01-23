/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:09:23 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/23 19:10:29 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_grid_cpy(t_map *map)
{
	char	**grid;
	int		i;

	i = 0;
	grid = malloc(sizeof(char *) * (map->height + 1));
	if (!grid)
		return (NULL);
	while (i < map->height)
	{
		grid[i] = ft_strdup(map->grid[i]);
		if (!grid[i])
		{
			ft_strsfree(grid, i - 1);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

t_pos	get_next_pos(t_pos pos, int direction)
{
	t_pos	next;

	next.height = pos.height;
	next.width = pos.width;
	if (direction == 1)
		next.height++;
	else if (direction == 2)
		next.height--;
	else if (direction == 3)
		next.width++;
	else
		next.width--;
	return (next);
}

void	flood_fill(char **grid, t_flood *count, t_map *map, t_pos pos)
{
	int		height;
	int		width;

	height = pos.height;
	width = pos.width;
	if (-1 < height && height < map->height && -1 < width && width < map->width)
	{
		if (grid[height][width] != '1' && grid[height][width] != 'X')
		{
			if (grid[height][width] == 'C')
				count->collectibles_found++;
			if (grid[height][width] == 'E')
				count->exit_found++;
			grid[height][width] = 'X';
			flood_fill(grid, count, map, get_next_pos(pos, 1));
			flood_fill(grid, count, map, get_next_pos(pos, 2));
			flood_fill(grid, count, map, get_next_pos(pos, 3));
			flood_fill(grid, count, map, get_next_pos(pos, 4));
		}
	}
}
