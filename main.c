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

int	main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	t_vars	vars;
	t_data	img;
	int		i;
	int		j;
	// t_map	*map;

	if (argc == 2)
	{
		filename = argv[1];
		if (!filename_is_correct(filename))
			return (ft_error("Filename not correct\n"));
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error while opening the file\n"));
		if (!is_rectangle(fd))
			return (ft_error("Map is not rectangle\n"));
		// map = gen_map(filename);
		close(fd);
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (ft_error("Issue with mlx_init"));
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
		img.img = mlx_new_image(vars.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		i = 0;
		while (i < 1080)
		{
			j = 0;
			while (j < 1920 && i % 5 == 0)
			{
				my_mlx_pixel_put(&img, j, i, 0x005800FF);
				j++;
			}
			i++;
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
		mlx_loop(vars.mlx);
	}
}
