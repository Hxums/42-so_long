/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:09:21 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/11 22:31:36 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (0);
}

int	ft_check_file(char *filename)
{
	int	fd;

	if (!filename_is_correct(filename))
		return (ft_error("Filename not correct\n"));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("Issue while opening the file\n"));
	if (!is_rectangle(fd))
	{
		close(fd);
		return (ft_error("Map is not rectangle\n"));
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (!map)
		return (ft_error("Map cannot be created (malloc issue)\n"));
	if (!map_surrounded_by_wall(map))
	{
		free_map_grid(map, map->height - 1);
		free(map);
		return (ft_error("Map not surrounded by wall\n"));
	}
	if (!map_is_valid(map))
	{
		free_map_grid(map, map->height - 1);
		free(map);
		return (ft_error("Map not valid\n"));
	}
	if (!map_can_be_done(map))
	{
		free_map_grid(map, map->height - 1);
		free(map);
		return (ft_error("Map can't be completed\n"));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	*map;
	t_game	*game;

	if (argc == 2)
	{
		if (!ft_check_file(argv[1]))
			return (0);
		map = gen_map(argv[1]);
		if (!check_map(map))
			return (0);
		game = init_game_struct(&vars, map, get_player_pos(map));
		if (!game)
		{
			free_map_grid(map, map->height - 1);
			free(map);
			return (ft_error("Error while init game\n"));
		}
		save_exit(game);
		launch_game(game, map);
	}
	else
		ft_printf("Error");
}
