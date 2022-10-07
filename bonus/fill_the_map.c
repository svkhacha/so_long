/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:55:40 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 17:47:28 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long_bonus.h"

static void	put_img(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, img,
		x * g->img_width, y * g->img_height);
}

static void	put_exit(t_game *g, int x, int y)
{
	if (g->end_of_game == 1)
		exit_the_game(g);
	put_img(g, g->img_exit, x, y);
}

static void	put_player(t_game *g, void *img, int x, int y)
{
	g->player_x = x;
	g->player_y = y;
	put_img(g, img, x, y);
}

void	fill_the_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->mlx_map[y])
	{
		x = 0;
		while (g->mlx_map[y][x])
		{
			if (g->mlx_map[y][x] == '1')
				put_img(g, g->img_wall, x, y);
			if (g->mlx_map[y][x] == '0')
				put_img(g, g->img_empty, x, y);
			if (g->mlx_map[y][x] == 'P')
				put_player(g, g->img_player, x, y);
			if (g->mlx_map[y][x] == 'C')
				put_img(g, g->img_collectible, x, y);
			if (g->mlx_map[y][x] == 'E')
				put_exit(g, x, y);
			x++;
		}
		y++;
	}
	for_moves(g);
}
