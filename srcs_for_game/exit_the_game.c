/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:50:34 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 15:05:56 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_new_tmp(char *new_tmp)
{
	if (new_tmp)
		free(new_tmp);
}

void	free_read_end(char *map_line, char *map_tmp, int fd)
{
	free(map_line);
	free(map_tmp);
	close(fd);
}

int	get_map_file(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		exit(1);
	return (fd);
}

int	exit_the_game(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img_empty);
	mlx_destroy_image(g->mlx, g->img_wall);
	mlx_destroy_image(g->mlx, g->img_player);
	mlx_destroy_image(g->mlx, g->img_collectible);
	mlx_destroy_image(g->mlx, g->img_exit);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free_map(g->mlx_map);
	free(g->mlx);
	exit(0);
	return (0);
}
