/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:18:48 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 16:58:24 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define KEY_D		2
# define KEY_A		0
# define KEY_W		13
# define KEY_S		1
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_ESC	53

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**mlx_map;

	void	*img_empty;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;

	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;

	int		player_count;
	int		collectible_count;
	int		exit_count;

	int		player_x;
	int		player_y;
	int		move;
	int		end_of_game;

}			t_game;

void	game_initialization(t_game *g);
void	check_my_map(t_game *g);
void	fill_the_map(t_game *g);
void	game_play(t_game *g);
void	move_d(t_game *g);
void	move_a(t_game *g);
void	move_w(t_game *g);
void	move_s(t_game *g);
void	free_map(char **map);
void	free_new_tmp(char *new_tmp);
void	free_read_end(char *map_line, char *map_tmp, int fd);
int		get_map_file(char *pathname);
int		exit_the_game(t_game *g);

#endif
