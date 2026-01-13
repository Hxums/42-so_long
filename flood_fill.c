/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:09:23 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/13 08:41:20 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **grid, t_flood *count, t_map *map, t_pos pos)
{
	int	height;
	int	width;

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
			pos.height = height - 1;
			flood_fill(grid, count, map, pos);
			pos.height = height + 1;
			flood_fill(grid, count, map, pos);
			pos.width = width - 1;
			flood_fill(grid, count, map, pos);
			pos.width = width + 1;
			flood_fill(grid, count, map, pos);
		}
	}
}
