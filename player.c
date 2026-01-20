/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:05:23 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/19 23:46:14 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	user_can_move(t_map *map, t_pos new_pos)
{
	if (map->grid[new_pos.height][new_pos.width] == '1')
		return (0);
	if (map->grid[new_pos.height][new_pos.width] == 'C')
		map->collectible--;
	if (map->grid[new_pos.height][new_pos.width] == 'E' &&
	map->collectible != 0)
		return (0);
	return (1);
}
