/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:44:40 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/17 21:05:49 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_tile_color(char c)
{
	if (c == '1')
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

void	draw_map(t_map *map, t_vars *vars, t_data *img)
{
	int	i;
	int	j;
	int	k;
	int	l;

	mlx_clear_window(vars->mlx, vars->win);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			k = -1;
			while (++k < TILE_SIZE)
			{
				l = -1;
				while (++l < TILE_SIZE)
				{
					my_mlx_pixel_put(img, j * TILE_SIZE + l,
						i * TILE_SIZE + k, get_tile_color(map->grid[i][j]));
				}
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
}

void	init_window(t_map *map, t_vars *vars, t_data *img)
{
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
	draw_map(map, vars, img);
}