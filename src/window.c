/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:44:40 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/25 12:41:51 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_sprite(t_game *game, char c)
{
	if (c == '1')
		return (game->sprites.wall);
	else if (c == '0')
		return (game->sprites.floor);
	else if (c == 'C')
		return (game->sprites.collectibles[game->collectible_frame]);
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
			if (game->exit_pos.height == i && game->exit_pos.width == j)
					img = game->sprites.exit;
			mlx_put_image_to_window(game->vars.mlx, game->vars.win, img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->sprites.player[game->player_direction - 1],
		game->player_pos.width * TILE_SIZE,
		game->player_pos.height * TILE_SIZE);
	if (game->exit_pos.height == game->player_pos.height
		&& game->exit_pos.width == game->player_pos.width)
		game->map->grid[game->exit_pos.height][game->exit_pos.width] = 'E';
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
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		return ;
	}
}
