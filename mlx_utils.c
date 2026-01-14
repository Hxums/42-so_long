/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:01:57 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/14 16:23:21 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_press(int keycode, t_vars *vars)
{
	printf("keycode is %d\n", keycode);
	if (keycode == 65307){
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 65362)
		printf("arrow up\n");
	if (keycode == 65364)
		printf("arrow down\n");
	if (keycode == 65361)
		printf("arrow left\n");
	if (keycode == 65363)
		printf("arrow right\n");
	return (0);
}