/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:56:15 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 16:50:10 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long.h"

static void	define_directions(int key, t_game *g)
{
	if (key == KEY_W || key == KEY_UP)
	{
		g->player_y--;
		move_w(g);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		g->player_y++;
		move_s(g);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		g->player_x++;
		move_d(g);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		g->player_x--;
		move_a(g);
	}
}

static int	count_moves(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_the_game(g);
	else if (g->end_of_game == 0)
	{
		define_directions(keycode, g);
		write(1, "MOVE ⭐️", 8);
		write(1, "\t", 1);
		ft_putnbr_fd(g->move, 1);
		write(1, "\n", 1);
	}
	return (0);
}

void	game_play(t_game *g)
{
	mlx_hook(g->mlx_win, 2, 1L << 0, count_moves, g);
	mlx_hook(g->mlx_win, 17, 1L << 17, exit_the_game, g);
}
