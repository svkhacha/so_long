/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:18:48 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 15:55:25 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long_bonus.h"

static void	img_initialization(t_game *g)
{
	g->img_empty = mlx_xpm_file_to_image(g->mlx, "./imgs/empty.xpm",
			&g->img_width, &g->img_height);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "./imgs/wall.xpm",
			&g->img_width, &g->img_height);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "./imgs/player_right.xpm",
			&g->img_width, &g->img_height);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "./imgs/exit.xpm",
			&g->img_width, &g->img_height);
	g->img_collectible = mlx_xpm_file_to_image(g->mlx, "./imgs/collectible.xpm",
			&g->img_width, &g->img_height);
}

static void	window_size(t_game *g)
{	
	int	i;

	i = 0;
	g->img_width = 80;
	g->img_height = 80;
	g->map_width = ft_strlen(g->mlx_map[0]) * g->img_width;
	while (g->mlx_map[i])
		++i;
	g->map_height = i * g->img_height;
}	

void	game_initialization(t_game *g)
{
	g->mlx = mlx_init();
	window_size(g);
	g->mlx_win = mlx_new_window(g->mlx, g->map_width, g->map_height,
			"Welcome to another MULTIVERSE !");
	img_initialization(g);
	g->move = 0;
	g->end_of_game = 0;
	fill_the_map(g);
}
