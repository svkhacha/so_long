/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:44:01 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/11 20:32:47 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long_bonus.h"

static void	change_player_img(char c, t_game *g)
{
	mlx_destroy_image(g->mlx, g->img_player);
	if (c == 'R')
		g->img_player = mlx_xpm_file_to_image(g->mlx, "imgs/player_right.xpm",
				&g->map_width, &g->map_height);
	else if (c == 'L')
		g->img_player = mlx_xpm_file_to_image(g->mlx, "imgs/player_left.xpm",
				&g->map_width, &g->map_height);
}

void	move_d(t_game *g)
{
	change_player_img('R', g);
	if (g->mlx_map[g->player_y][g->player_x] == 'E'
			&& g->collectible_count == 0)
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		g->mlx_map[g->player_y][g->player_x - 1] = '0';
		g->end_of_game = 1;
		g->move++;
		fill_the_map(g);
	}
	else if (g->mlx_map[g->player_y][g->player_x] == 'E'
			|| g->mlx_map[g->player_y][g->player_x] == '1')
		g->player_x--;
	else
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		if (g->mlx_map[g->player_y][g->player_x] == 'C')
			g->collectible_count--;
		g->mlx_map[g->player_y][g->player_x] = 'P';
		g->move++;
		g->mlx_map[g->player_y][g->player_x - 1] = '0';
		fill_the_map(g);
	}
}

void	move_a(t_game *g)
{
	change_player_img('L', g);
	if (g->mlx_map[g->player_y][g->player_x] == 'E'
			&& g->collectible_count == 0)
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		g->mlx_map[g->player_y][g->player_x + 1] = '0';
		g->end_of_game = 1;
		g->move++;
		fill_the_map(g);
	}
	else if (g->mlx_map[g->player_y][g->player_x] == 'E'
			|| g->mlx_map[g->player_y][g->player_x] == '1')
		g->player_x++;
	else
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		if (g->mlx_map[g->player_y][g->player_x] == 'C')
			g->collectible_count--;
		g->mlx_map[g->player_y][g->player_x] = 'P';
		g->move++;
		g->mlx_map[g->player_y][g->player_x + 1] = '0';
		fill_the_map(g);
	}
}

void	move_w(t_game *g)
{
	if (g->mlx_map[g->player_y][g->player_x] == 'E'
			&& g->collectible_count == 0)
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		g->mlx_map[g->player_y + 1][g->player_x] = '0';
		g->end_of_game = 1;
		g->move++;
		fill_the_map(g);
	}
	else if (g->mlx_map[g->player_y][g->player_x] == 'E'
			|| g->mlx_map[g->player_y][g->player_x] == '1')
		g->player_y++;
	else
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		if (g->mlx_map[g->player_y][g->player_x] == 'C')
			g->collectible_count--;
		g->mlx_map[g->player_y][g->player_x] = 'P';
		g->move++;
		g->mlx_map[g->player_y + 1][g->player_x] = '0';
		fill_the_map(g);
	}
}

void	move_s(t_game *g)
{
	if (g->mlx_map[g->player_y][g->player_x] == 'E'
			&& g->collectible_count == 0)
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		g->mlx_map[g->player_y - 1][g->player_x] = '0';
		g->end_of_game = 1;
		g->move++;
		fill_the_map(g);
	}
	else if (g->mlx_map[g->player_y][g->player_x] == 'E'
			|| g->mlx_map[g->player_y][g->player_x] == '1')
		g->player_y--;
	else
	{
		mlx_clear_window(g->mlx, g->mlx_win);
		if (g->mlx_map[g->player_y][g->player_x] == 'C')
			g->collectible_count--;
		g->mlx_map[g->player_y][g->player_x] = 'P';
		g->move++;
		g->mlx_map[g->player_y - 1][g->player_x] = '0';
		fill_the_map(g);
	}
}
