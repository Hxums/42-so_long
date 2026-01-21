/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:01:57 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/21 17:38:26 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_movements(t_game *game)
{
	char	*num;

	ft_printf("Move %d\n", game->move_number);
	num = ft_itoa(game->move_number);
	mlx_string_put(game->vars.mlx, game->vars.win, 50, 50, 0xFFFFFF, "Move :");
	mlx_string_put(game->vars.mlx, game->vars.win, 100, 50, 0xFFFFFF, num);
	free(num);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->sprites.collectible);
	mlx_destroy_image(game->vars.mlx, game->sprites.exit);
	mlx_destroy_image(game->vars.mlx, game->sprites.floor);
	mlx_destroy_image(game->vars.mlx, game->sprites.player);
	mlx_destroy_image(game->vars.mlx, game->sprites.wall);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free_map_grid(game->map, game->map->height - 1);
	free(game->map);
	free(game->vars.mlx);
	free(game);
	exit(0);
}

void	move_player(t_game *game, int direction)
{
	t_pos	new_pos;
	int		exit;

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
		exit = game->map->grid[new_pos.height][new_pos.width] == 'E';
		game->move_number++;
		show_movements(game);
		if (exit && game->map->collectible == 0)
			close_window(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	if (119 <= keycode && keycode <= 65364)
		move_player(game, keycode - 65360);
	return (0);
}
