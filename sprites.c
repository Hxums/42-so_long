/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 09:29:47 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/19 20:08:05 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(void *mlx, t_sprites *sprites)
{
	int	w;
	int	h;

	sprites->wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &w, &h);
	sprites->floor = mlx_xpm_file_to_image(mlx, "sprites/floor.xpm", &w, &h);
	sprites->player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm", &w, &h);
	sprites->collectible = mlx_xpm_file_to_image(mlx, "sprites/collectible.xpm",
			&w, &h);
	sprites->exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm",
			&w, &h);
}
