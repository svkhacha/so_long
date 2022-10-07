/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:37:22 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 15:50:58 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "so_long_bonus.h"

static int	check_argv(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	--i;
	if (s[i] == 'r' && s[i - 1] == 'e'
		&& s[i - 2] == 'b' && s[i - 3] == '.')
		return (1);
	return (0);
}

static char	*check_map_split(char *map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i] == '\n' && map[i - 1] == '\n')
		{
			write(2, "❌ ERROR: Invalid map\n", 23);
			exit(1);
		}
		i++;
	}
	return (map);
}

static void	read_check_the_map(char	*pathname, t_game *g)
{
	int		fd;
	char	*map_line;
	char	*map_tmp;
	char	*new_tmp;
	char	*map;

	new_tmp = NULL;
	map = NULL;
	fd = get_map_file(pathname);
	map_tmp = ft_strdup("");
	while (1)
	{
		map_line = get_next_line(fd);
		free_new_tmp(new_tmp);
		if (map_line == '\0')
			break ;
		new_tmp = map_line;
		map = map_tmp;
		map_tmp = ft_strjoin(check_map_split(map_tmp), map_line);
		free(map);
	}
	g->mlx_map = ft_split(map_tmp, '\n');
	free_read_end(map_line, map_tmp, fd);
	check_my_map(g);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc == 2 && check_argv(argv[1]))
	{
		read_check_the_map(argv[1], &g);
		game_initialization(&g);
		game_play(&g);
		mlx_loop(g.mlx);
	}
	else
	{
		write(2, "❌ ERROR: Invalid syntax\n", 26);
		exit(1);
	}
	return (0);
}
