/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:01:57 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/19 02:18:38 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int direction)
{
	t_pos	new_pos;

	new_pos = game->player_pos;
	if (direction == 1)
		new_pos.width--;
	else if (direction == 2)
		new_pos.height--;
	else if (direction == 3)
		new_pos.width++;
	else
		new_pos.height++;
	if (user_can_move(game->map, new_pos))
	{
		game->map->grid[game->player_pos.height][game->player_pos.width] = '0';
		game->map->grid[new_pos.height][new_pos.width] = 'P';
		game->player_pos = new_pos;
		draw_map(game);
		draw_player(game);
		game->move_number++;
		printf("move number : %d\n", game->move_number);
	}
}

int	close_window(t_game *game)
{
	if (game->sprites.collectible)
		mlx_destroy_image(game->vars.mlx, game->sprites.collectible);
	if (game->sprites.exit)
		mlx_destroy_image(game->vars.mlx, game->sprites.exit);
	if (game->sprites.floor)
		mlx_destroy_image(game->vars.mlx, game->sprites.floor);
	if (game->sprites.player)
		mlx_destroy_image(game->vars.mlx, game->sprites.player);
	if (game->sprites.wall)
		mlx_destroy_image(game->vars.mlx, game->sprites.wall);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free_map_grid(game->map, game->map->height - 1);
	free(game->map);
	free(game->vars.mlx);
	free(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (119 <= keycode && keycode <= 65364)
		move_player(game, keycode - 65360);
	return (0);
}
