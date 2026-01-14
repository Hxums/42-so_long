/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:44:40 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/14 23:54:34 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_tile_color(char c)
{
	if (c == '1')
		return (COLOR_WALL);
	else if (c == '1')
		return (COLOR_WALL);
	else if (c == '0')
		return (COLOR_FLOOR);
	else if (c == 'P')
		return (COLOR_PLAYER);
	else if (c == 'E')
		return (COLOR_EXIT);
	else if (c == 'C')
		return (COLOR_COLLECT);
	else
		return (COLOR_UNKNOWN);
}

void	init_window(t_map *map, t_vars *vars, t_data *img)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		color;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	vars->win = mlx_new_window(vars->mlx, TILE_SIZE * map->width,
			TILE_SIZE * map->height, "hcissoko so_long");
	if (!vars->win)
	{
		free(vars->mlx);
		return ;
	}
	img->img = mlx_new_image(vars->mlx, TILE_SIZE * map->width,
			TILE_SIZE * map->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			color = get_tile_color(map->grid[y][x]);
			i = 0;
			while (i < TILE_SIZE)
			{
				j = 0;
				while (j < TILE_SIZE)
				{
					my_mlx_pixel_put(img, x * TILE_SIZE + j,
						y * TILE_SIZE + i, color);
					j++;
				}
				i++;
			}
			x++;
		}
		y++;
	}
}
