/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:01:57 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/17 01:56:18 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
		draw_map(game->map, &(game->vars), &(game->img), 1);
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		close_window(game);
	}
	if (65361 <= keycode && keycode <= 65364)
	{
		// printf("arrow %d\n", keycode - 65360);
		move_player(game, keycode - 65360);
	}
	else
		printf("keycode is %d\n", keycode);
	return (0);
}
