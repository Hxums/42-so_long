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
# include <sys/time.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"

# define EXTENSION ".ber"
# define TILE_SIZE 64
# define NB_COLLECTIBLE_FRAMES 8

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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*player[4];
	void	*collectibles[NB_COLLECTIBLE_FRAMES];
	void	*exit;
}	t_sprites;

typedef struct s_game
{
	t_vars			vars;
	t_map			*map;
	t_pos			player_pos;
	t_sprites		sprites;
	int				move_number;
	t_pos			exit_pos;
	int				collectible_frame;
	int				player_direction;
	struct timeval	last_anim_time;
}	t_game;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		filename_is_correct(char *str);
int		is_rectangle(int fd);
char	*ft_itoa(int n);
t_map	*gen_map(char *filename);
void	ft_strsfree(char **strs, int i);
char	**ft_grid_cpy(t_map *map);
void	free_map_grid(t_map *map, int i);
int		map_surrounded_by_wall(t_map *map);
int		map_is_valid(t_map *map);
int		map_can_be_done(t_map *map);
t_pos	get_player_pos(t_map *map);
void	flood_fill(char **grid, t_flood *count, t_map *map, t_pos pos);
int		key_press(int keycode, t_game *game);
void	init_window(t_game *game);
int		user_can_move(t_map *map, t_pos new_pos);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		close_window(t_game *game);
void	load_sprites(void *mlx, t_sprites *sprites);
t_game	*init_game_struct(t_vars *vars, t_map *map, t_pos pos);
void	launch_game(t_game *game, t_map *map);
t_game	*init_game_struct(t_vars *vars, t_map *map, t_pos pos);
int		ft_error(char *str);
void	launch_game(t_game *game, t_map *map);
void	show_movements(t_game *game);
void	save_exit(t_game *game);
int		animate_collectibles(t_game *game);
int		expose_redraw(t_game *game);
int		get_line_len(char *line);
void	empty_fd(int fd);

#endif