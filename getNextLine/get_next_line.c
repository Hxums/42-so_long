/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:34:42 by hcissoko          #+#    #+#             */
/*   Updated: 2025/12/10 14:45:16 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_affect_temp(char *temp, char *buffer)
{
	char	*save;

	save = NULL;
	if (temp)
	{
		save = ft_strdup(temp);
		free(temp);
		temp = ft_strjoin(save, buffer);
		free(save);
	}
	else
		temp = ft_strdup(buffer);
	return (temp);
}

void	ft_extract_ln(char **ptr_temp)
{
	char	*keep_temp;

	keep_temp = ft_strdup(ft_strchr(*ptr_temp, '\n') + 1);
	free(*ptr_temp);
	*ptr_temp = keep_temp;
}
/*
We use ptr to free in the function
There is 3 cases
- EOF so we free all and line = temp
- Text contain \n so we return only the text before \n
- Empty text
*/

char	*ft_getline(char **ptr_temp, char **ptr_buffer, int bytes_read)
{
	char	*line;
	int		end;

	line = NULL;
	if (*ptr_temp && **ptr_temp && bytes_read == 0)
		line = ft_strdup(*ptr_temp);
	if (ft_strchr(*ptr_temp, '\n'))
	{
		end = ft_strlen(*ptr_temp) - ft_strlen(ft_strchr(*ptr_temp, '\n')) + 1;
		line = ft_substr(*ptr_temp, 0, end);
		ft_extract_ln(ptr_temp);
		return (line);
	}
	free(*ptr_temp);
	*ptr_temp = NULL;
	free(*ptr_buffer);
	*ptr_buffer = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	int			bytes_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	bytes_read = 1;
	buffer = NULL;
	while (0 < bytes_read)
	{
		if (ft_strchr(temp, '\n'))
			return (ft_getline(&temp, &buffer, bytes_read));
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_affect_temp(temp, buffer);
		free(buffer);
		buffer = NULL;
	}
	return (ft_getline(&temp, &buffer, bytes_read));
}

// int	main(int argc, char **argv)
// {
// 	char	*filename;
// 	int		fd;
// 	char	*line;

// 	if (argc == 1)
// 		printf("File name is missing.\n");
// 	else if (argc > 2)
// 		printf("Too many arguments.\n");
// 	else
// 	{
// 		filename = argv[1];
// 		fd = open(filename, O_RDONLY);
// 		line = get_next_line(fd);
// 		while (line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		printf("\n");
// 		close(fd);
// 	}
// }
