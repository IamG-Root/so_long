/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:02:49 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:07:39 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movtype_w(int command, t_game *game)
{
	if (command == 13)
	{
		if (game->map[game->py - 1][game->px] == '1')
			return (0);
		else if (game->map[game->py - 1][game->px] == 'E' && game->coins == 0)
			endgame(game, 5);
		else if (game->map[game->py - 1][game->px] == 'E' && game->coins > 0)
			return (0);
		else if (game->map[game->py - 1][game->px] == 'C')
		{
			game->coins--;
			game->map[game->py][game->px] = '0';
			game->map[game->py - 1][game->px] = 'P';
			return (1);
		}
		else if (game->map[game->py - 1][game->px] == 'X')
			endgame(game, 4);
		else
		{
			game->map[game->py][game->px] = '0';
			game->map[game->py - 1][game->px] = 'P';
			return (1);
		}
	}
	return (0);
}

int	movtype_a(int command, t_game *game)
{
	if (command == 0)
	{
		if (game->map[game->py][game->px - 1] == '1')
			return (0);
		else if (game->map[game->py][game->px - 1] == 'E' && game->coins == 0)
			endgame(game, 5);
		else if (game->map[game->py][game->px - 1] == 'E' && game->coins > 0)
			return (0);
		else if (game->map[game->py][game->px - 1] == 'X')
			endgame(game, 4);
		else if (game->map[game->py][game->px - 1] == 'C')
		{
			game->coins--;
			game->map[game->py][game->px] = '0';
			game->map[game->py][game->px - 1] = 'P';
			return (1);
		}
		else
		{
			game->map[game->py][game->px] = '0';
			game->map[game->py][game->px - 1] = 'P';
			return (1);
		}
	}
	return (0);
}

int	movtype_s(int command, t_game *game)
{
	if (command == 1)
	{
		if (game->map[game->py + 1][game->px] == '1')
			return (0);
		else if (game->map[game->py + 1][game->px] == 'E' && game->coins == 0)
			endgame(game, 5);
		else if (game->map[game->py + 1][game->px] == 'E' && game->coins > 0)
			return (0);
		else if (game->map[game->py + 1][game->px] == 'X')
			endgame(game, 4);
		else if (game->map[game->py + 1][game->px] == 'C')
		{
			game->coins--;
			game->map[game->py][game->px] = '0';
			game->map[game->py + 1][game->px] = 'P';
			return (1);
		}
		else
		{
			game->map[game->py][game->px] = '0';
			game->map[game->py + 1][game->px] = 'P';
			return (1);
		}
	}
	return (0);
}

int	movtype_d(int command, t_game *game)
{
	if (command == 2)
	{
		if (game->map[game->py][game->px + 1] == '1')
			return (0);
		else if (game->map[game->py][game->px + 1] == 'E' && game->coins == 0)
			endgame(game, 5);
		else if (game->map[game->py][game->px + 1] == 'E' && game->coins > 0)
			return (0);
		else if (game->map[game->py][game->px + 1] == 'X')
			endgame(game, 4);
		else if (game->map[game->py][game->px + 1] == 'C')
		{
			game->coins--;
			game->map[game->py][game->px] = '0';
			game->map[game->py][game->px + 1] = 'P';
			return (1);
		}
		else
		{
			game->map[game->py][game->px] = '0';
			game->map[game->py][game->px + 1] = 'P';
			return (1);
		}
	}
	return (0);
}

int	controls_runtime(int command, t_game *game)
{
	int		checkmove;

	checkmove = 0;
	if (command == 53)
		endgame(game, 6);
	if (command == 13)
		checkmove = movtype_w(command, game);
	if (command == 0)
		checkmove = movtype_a(command, game);
	if (command == 1)
		checkmove = movtype_s(command, game);
	if (command == 2)
		checkmove = movtype_d(command, game);
	if (checkmove != 0)
	{
		game->totalmoves++;
		display_images(game);
		display_player(game);
		ft_printf("Total moves: %d\n", game->totalmoves);
		ft_printf("Gems remaining: %d\n", game->coins);
	}
	return (0);
}
