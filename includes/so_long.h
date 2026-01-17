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
# include "mlx.h"

# ifndef EXTENSION
#  define EXTENSION ".ber"
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_flood
{
	int	collectibles_found;
	int	exit_found;
}	t_flood;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

enum e_tile_color
{
	COLOR_WALL		= 0x2E3440,
	COLOR_FLOOR		= 0xECEFF4,
	COLOR_PLAYER	= 0x5E81AC,
	COLOR_EXIT		= 0xA3BE8C,
	COLOR_COLLECT	= 0xEBCB8B,
	COLOR_UNKNOWN	= 0xBF616A
};

typedef struct s_game
{
	t_vars	vars;
	t_map	*map;
	t_pos	player_pos;
	t_data	img;
}	t_game;

int		filename_is_correct(char *str);
int		is_rectangle(int fd);
t_map	*gen_map(char *filename);
void	ft_strsfree(char **strs, int i);
char	**ft_grid_cpy(t_map *map);
int		map_surrounded_by_wall(t_map *map);
int		map_is_valid(t_map *map);
int		map_can_be_done(t_map *map);
t_pos	get_player_pos(t_map *map);
void	flood_fill(char **grid, t_flood *count, t_map *map, t_pos pos);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press(int keycode, t_game *game);
void	init_window(t_map *map, t_vars *vars, t_data *img);
int		user_can_move(t_map *map, t_pos new_pos);
void	draw_map(t_map *map, t_vars *vars, t_data *img, int clear_to_redraw);
int		close_window(t_game *game);
#endif