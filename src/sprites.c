/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 09:29:47 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/24 13:25:04 by hcissoko         ###   ########.fr       */
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
	sprites->collectibles[0] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_0.xpm", &w, &h);
	sprites->collectibles[1] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_1.xpm", &w, &h);
	sprites->collectibles[2] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_2.xpm", &w, &h);
	sprites->collectibles[3] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_3.xpm", &w, &h);
	sprites->collectibles[4] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_4.xpm", &w, &h);
	sprites->collectibles[5] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_5.xpm", &w, &h);
	sprites->collectibles[6] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_6.xpm", &w, &h);
	sprites->collectibles[7] = mlx_xpm_file_to_image(mlx,
			"sprites/collectible_7.xpm", &w, &h);
	sprites->exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &w, &h);
}
