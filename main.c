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

#include <fcntl.h>
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
	t_map	*map;

	if (argc == 2)
	{
		filename = argv[1];
		if (!filename_is_correct(filename))
			return (ft_error("Filename not correct"));
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error while opening the file"));
		if (!is_rectangle(fd))
			return (ft_error("Map is not rectangle"));
		map = gen_map(filename);
		close(fd);
		return (0);
	}
}
