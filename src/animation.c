/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:32:16 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/31 19:44:27 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_movements(t_game *game)
{
	char	*num;

	if (game->move_number == 0)
		return ;
	num = ft_itoa(game->move_number);
	if (num)
	{
		mlx_string_put(game->vars.mlx, game->vars.win, 50, 50, 0xFFFFFF,
			"Move :");
		mlx_string_put(game->vars.mlx, game->vars.win, 100, 50, 0xFFFFFF, num);
		free(num);
	}
}

int	animate_collectibles(t_game *game)
{
	struct timeval	now;
	long			elapsed_ms;

	gettimeofday(&now, NULL);
	if (game->last_anim_time.tv_sec == 0 && game->last_anim_time.tv_usec == 0)
		game->last_anim_time = now;
	elapsed_ms = (now.tv_sec - game->last_anim_time.tv_sec) * 1000
		+ (now.tv_usec - game->last_anim_time.tv_usec) / 1000;
	if (elapsed_ms >= 200)
	{
		game->collectible_frame = (game->collectible_frame + 1)
			% NB_COLLECTIBLE_FRAMES;
		game->last_anim_time = now;
		draw_map(game);
		draw_player(game);
		show_movements(game);
	}
	return (0);
}

int	expose_redraw(t_game *game)
{
	draw_map(game);
	draw_player(game);
	return (0);
}
