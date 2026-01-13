/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 07:59:20 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/13 08:08:05 by hcissoko         ###   ########.fr       */
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