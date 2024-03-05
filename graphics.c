/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:04:46 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:08:04 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_images(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/wall.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/stone.xpm", &i, &j);
	game->xexit = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/infinity_s.xpm", &i, &j);
	game->xplayer = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/thanos.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/enemy.xpm", &i, &j);
	game->enemy_a = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/enemy_a.xpm", &i, &j);
	game->enemy_s = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/enemy.xpm", &i, &j);
	game->xexit2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/infinity_e.xpm", &i, &j);
	game->holder = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/holder.xpm", &i, &j);
}

void	display_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (x < game->widthmap)
		{
			if (game->map[y][x] == '1')
				put_images(game, 1, x, y);
			if (game->map[y][x] == '0')
				put_images(game, 2, x, y);
			if (game->map[y][x] == 'E' && game->coins > 0)
				put_images(game, 3, x, y);
			if (game->map[y][x] == 'E' && game->coins == 0)
				put_images(game, 4, x, y);
			if (game->map[y][x] == 'C')
				put_images(game, 5, x, y);
			if (game->map[y][x] == 'X')
				put_images(game, 6, x, y);
			x++;
		}
		y++;
	}
}

void	display_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (x < game->widthmap)
		{
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->xplayer, x * 39, y * 39);
				game->px = x;
				game->py = y;
			}
			x++;
		}
		y++;
	}
	x = -1;
	while (x++ < game->widthmap)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->holder, x * 39, y * 45);
}

void	put_images(t_game *game, int img, int x, int y)
{
	if (img == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->wall, x * 39, y * 39);
	else if (img == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->floor, x * 39, y * 39);
	else if (img == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->xexit, x * 39, y * 39);
	else if (img == 4)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->xexit2, x * 39, y * 39);
	else if (img == 5)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->collectable, x * 39, y * 39);
	else if (img == 6)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->enemy, x * 39, y * 39);
}

int	animation(t_game *game)
{
	static int	counter = 0;
	char		*moves;

	moves = ft_itoa(game->totalmoves);
	counter++;
	if (counter == 200)
		game->enemy = game->enemy_s;
	else if (counter >= 400)
	{
		game->enemy = game->enemy_a;
		counter = 0;
	}
	display_images(game);
	display_player(game);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10,
		(game->heightmap * 45) + 20, 0xFF99FF, "TOTAL MOVES:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 150,
		(game->heightmap * 45) + 20, 0xFF99FF, moves);
	free(moves);
	return (0);
}
