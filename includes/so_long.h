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
	int		height;
	int		width;
	int		collectible;
}	t_map;

typedef struct s_pos
{
	int	height;
	int	width;
}	t_pos;

typedef struct s_flood
{
	int	collectibles_found;
	int	exit_found;
}	t_flood;


int		filename_is_correct(char *str);
int		is_rectangle(int fd);
t_map	*gen_map(char *filename);
void	ft_strsfree(char **strs, int i);
char	*ft_strdup(const char *s);
char	**ft_grid_cpy(t_map *map);
t_pos	get_player_pos(t_map *map);
void	flood_fill(char **grid, t_flood *count, t_map *map, t_pos pos);
#endif