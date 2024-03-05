/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:07:26 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:08:30 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

void	printerror(int errcode)
{
	if (errcode == -1)
		ft_printf("Error\nInvalid map file\n");
	else if (errcode == 0)
		ft_printf("Error\nInvalid map shape,it should be a rectangle\n");
	else if (errcode == 1)
		ft_printf("Error\nWall issue, check horizontal or vertical walls.\n");
	else if (errcode == 3)
		ft_printf("Error\nMissing items, maybe player, exit or collectables\n");
	else if (errcode == 4)
		ft_printf ("The Avengers killed you, try in another universe\n");
	else if (errcode == 5)
		ft_printf("YOU WIN --- THE UNIVERSE HAS BEEN DUSTED\n");
	else if (errcode == 6)
		ft_printf("Game has been closed\n");
}

void	endgame(t_game *game, int errcode)
{
	int	i;

	i = 0;
	printerror(errcode);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit (0);
}

int	endgame_x(t_game *game)
{
	endgame(game, 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf ("Too few or too many arguments!\n"));
	ft_check_map_name(argv[1]);
	ft_memset(&game, 0, sizeof(t_game));
	ft_loadmap(&game, argv[1]);
	if (!check_map_sqr(&game))
		endgame(&game, 0);
	if (!check_hor_walls(&game) || !check_ver_walls(&game))
		endgame(&game, 1);
	if (!check_items(&game))
		endgame(&game, 3);
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.widthmap * 39,
			game.heightmap * 64, "so_long");
	setup_images(&game);
	display_images(&game);
	display_player(&game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_key_hook(game.mlx_win, controls_runtime, &game);
	mlx_hook(game.mlx_win, 17, 0, endgame_x, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
