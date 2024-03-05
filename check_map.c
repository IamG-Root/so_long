/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:01:04 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:06:20 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->coins == 0 || game->exit == 0)
		return (0);
	return (1);
}

int	check_hor_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game->map[game->heightmap - 1][i])
	{
		if (game->map[game->heightmap - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_ver_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
	{
		if (game->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->heightmap)
	{
		if (game->map[i][game->widthmap - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_sqr(t_game *game)
{
	int		i;
	size_t	llen;

	i = 1;
	llen = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != llen)
			return (0);
		i++;
	}
	game->widthmap = llen;
	return (1);
}

int	ft_loadmap(t_game *game, char *path)
{
	int		fd;
	int		righe;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printerror(-1);
		exit(0);
	}
	righe = ft_countrows(fd);
	i = -1;
	if (righe == 0)
	{
		printerror(-1);
		exit(0);
	}
	game->map = malloc(sizeof(char *) * righe + 1);
	game->map[righe] = NULL;
	game->heightmap = righe;
	fd = open(path, O_RDONLY);
	while (i++ < righe)
		game->map[i] = get_next_line(fd);
	return (1);
}
