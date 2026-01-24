/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:19:22 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/24 13:48:01 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game_struct(t_vars *vars, t_map *map, t_pos pos)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->last_anim_time.tv_sec = 0;
	game->last_anim_time.tv_usec = 0;
	game->vars = *vars;
	game->map = map;
	game->player_pos = pos;
	game->move_number = 0;
	game->collectible_frame = 0;
	while (i < NB_COLLECTIBLE_FRAMES)
		game->sprites.collectibles[i++] = NULL;
	return (game);
}

void	launch_game(t_game *game, t_map *map)
{
	init_window(game);
	if (!game->vars.mlx)
	{
		free_map_grid(map, map->height - 1);
		free(game);
		ft_error("Error while init window");
	}
	load_sprites(game->vars.mlx, &game->sprites);
	draw_map(game);
	draw_player(game);
	mlx_hook(game->vars.win, 2, 1L, key_press, game);
	mlx_hook(game->vars.win, 17, 0, close_window, game);
	mlx_expose_hook(game->vars.win, expose_redraw, game);
	mlx_loop_hook(game->vars.mlx, animate_collectibles, game);
	mlx_loop(game->vars.mlx);
}

void	save_exit(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->grid[i][j] == 'E')
			{
				game->exit_pos.height = i;
				game->exit_pos.width = j;
				return ;
			}
		}
	}
}
