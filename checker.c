/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:12:30 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/12 01:07:00 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	filename_is_correct(char *str)
{
	int		size;
	int		i;
	t_map	map;

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