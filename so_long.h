/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:44:27 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:09:21 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		coins;
	int		player;
	int		exit;
	int		px;
	int		py;
	int		totalmoves;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*xexit;
	void	*xexit2;
	void	*xplayer;
	void	*enemy;
	void	*enemy_a;
	void	*enemy_s;
	void	*holder;
}	t_game;
void	ft_check_map_name(char *path);
void	printerror(int errcode);
void	endgame(t_game *game, int errcode);
void	setup_images(t_game *game);
void	display_images(t_game *game);
void	display_player(t_game *game);
void	put_images(t_game *game, int img, int x, int y);
int		endgame_x(t_game *game);
int		animation(t_game *game);
int		check_items(t_game *game);
int		check_hor_walls(t_game *game);
int		check_ver_walls(t_game *game);
int		check_map_sqr(t_game *game);
int		ft_countrows(int fd);
int		ft_loadmap(t_game *game, char *path);
int		movtype_w(int command, t_game *game);
int		movtype_a(int command, t_game *game);
int		movtype_s(int command, t_game *game);
int		movtype_d(int command, t_game *game);
int		controls_runtime(int command, t_game *game);
char	*ft_itoa(int n);
#endif
