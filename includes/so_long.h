/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:57:54 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/11 19:06:15 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"

# ifndef EXTENSION
#  define EXTENSION ".ber"
# endif

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectible;
}	t_map;

int		filename_is_correct(char *str);
int		is_rectangle(int fd);
t_map	*gen_map(char *filename);
#endif