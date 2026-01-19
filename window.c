/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:44:40 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/19 02:01:21 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_sprite(t_game *game, char c)
{
	if (c == '1')
		return (game->sprites.wall);
	else if (c == '0')
		return (game->sprites.floor);
	else if (c == 'P')
		return (game->sprites.player);
	else if (c == 'C')
		return (game->sprites.collectible);
	else if (c == 'E')
		return (game->sprites.exit);
	else
		return (NULL);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	mlx_clear_window(game->vars.mlx, game->vars.win);
	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->grid[i][j] == 'P')
				img = game->sprites.floor;
			else
				img = get_sprite(game, game->map->grid[i][j]);
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->sprites.player,
		game->player_pos.width * TILE_SIZE,
		game->player_pos.height * TILE_SIZE);
}

void	init_window(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return ;
	game->vars.win = mlx_new_window(game->vars.mlx,
			TILE_SIZE * game->map->width,
			TILE_SIZE * game->map->height, "hcissoko so_long");
	if (!game->vars.win)
	{
		free(game->vars.mlx);
		return ;
	}
}
