/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_my_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:23:27 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/11 20:16:06 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long_bonus.h"

static int	check_rectangle(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[++i])
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
	return (1);
}

static int	check_wall(char **map)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (map[i])
		++i;
	j = -1;
	while (map[0][++j] && map[i - 1][j])
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
	i = 0;
	len = ft_strlen(map[i]);
	while (map[++i])
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
	return (1);
}

static int	check_validation(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
					&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
	}
	return (1);
}

static int	check_right_count(t_game *g)
{
	int	i;
	int	j;

	g->player_count = 0;
	g->collectible_count = 0;
	g->exit_count = 0;
	i = 0;
	while (g->mlx_map[++i])
	{
		j = 0;
		while (g->mlx_map[i][++j])
		{
			if (g->mlx_map[i][j] == 'P')
				g->player_count++;
			else if (g->mlx_map[i][j] == 'C')
				g->collectible_count++;
			else if (g->mlx_map[i][j] == 'E')
				g->exit_count++;
		}
	}
	if (g->player_count != 1 || g->collectible_count == 0
		|| g->exit_count == 0)
		return (0);
	return (1);
}

void	check_my_map(t_game *g)
{
	if (check_rectangle(g->mlx_map) == 1 && check_wall(g->mlx_map) == 1
		&& check_validation(g->mlx_map) == 1 && check_right_count(g) == 1)
		return ;
	else
	{
		if (g->mlx_map)
			free_map(g->mlx_map);
		write(2, "❌ ERROR: Invalid map\n", 23);
		exit (1);
	}
}
