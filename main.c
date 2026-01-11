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

int	is_rectangle(int fd)
{
	char	*line;
	size_t	line_len;
	size_t	current_len;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 1;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	while (line)
	{
		current_len = ft_strlen(line);
		if (line[current_len - 1] == '\n')
			current_len--;
		if (line_len != current_len)
			return (0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i > 1);

}

int	main(int argc, char **argv)
{
	char	*filename;
	int		fd;

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
		printf("\n");
		close(fd);
		fd = open(filename, O_RDONLY);
		return (0);
	}
}