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
		return (ft_error("Error while opening the file\n"));
	if (!is_rectangle(fd))
	{
		close(fd);
		return (ft_error("Map is not rectangle\n"));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	t_map	*map;

	if (argc == 2)
	{
		if (!ft_check_file(argv[1]))
			return (0);
		map = gen_map(argv[1]);
		if (!map)
			return (0);
		if (!map_surrounded_by_wall(map))
		{
			free(map);
			return (ft_error("Map not surrounded by wall\n"));
		}
		if (!map_is_valid(map))
		{
			free(map);
			return (ft_error("Map not valid\n"));
		}
		if (!map_can_be_done(map))
		{
			free(map);
			return (ft_error("Map can't be completed\n"));
		}
		init_window(map, &vars, &img);
		if (!vars.mlx)
		{
			free(map);
			return (ft_error("Error while init window"));
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
		mlx_loop(vars.mlx);
		free(vars.mlx);
		free(vars.win);
	}
}
