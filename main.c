/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:09:21 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/11 19:51:23 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	filename_is_correct(char *str)
{
	int		size;
	int		i;

	size = ft_strlen(str);
	i = 0;
	if (size < 5)
		return (0);
	while (EXTENSION[i] && str[size - ft_strlen(EXTENSION) + i])
	{
		if (EXTENSION[i] != str[size - ft_strlen(EXTENSION) + i])
			return (0);
		i++;
	}
	return (EXTENSION[i] == str[size - ft_strlen(EXTENSION) + i]);
}

// int	is_rectangle(char	)
// {

// }

int	main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	char	*line;
	int		line_len;

	if (argc == 2)
	{
		filename = argv[1];
		if (!filename_is_correct(filename))
			return (ft_error("Filename not correct"));
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (ft_error("Error while opening the file"));
		line = get_next_line(fd);
		line_len = ft_strlen(line); 
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		printf("\n");
		close(fd);
	}
}