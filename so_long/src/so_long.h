/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:22:01 by mwin              #+#    #+#             */
/*   Updated: 2025/08/11 14:53:49 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "ft_printf_gnl.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	void			*wall;
	void			*floor;
	void			*avatar;
	void			*collectible;
	void			*exit;
	char			**map;
	int				sizeof_tile;
	int				avatar_x;
	int				avatar_y;
	int				window_x;
	int				window_y;
	unsigned int	movements;
	int				frame_lft;
	int				frame_tp;
	int				frame_rght;
	int				frame_btm;
}	t_game;

void	error_message(char	*error_msg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	access_fail_exit(char *error_msg, t_game *game);
void	listen_to_events(t_game *game);
void	clean_program(t_game *game);
int		quit_program(t_game *game);
int		is_rectangle(char **map);
int		check_fullwall(char **map);
t_point	locate_avatar(char **map);
int		check_path(char **map);
void	free_map(char **map);
char	**duplicate_map(char **map);
int		components_exist(char **map);
int		check_count(char **map);
char	**check_map(const char *file);
int		move_avatar(int key, t_game *game);
void	frame_avatar(t_game *game);
void	initialise_game_display(t_game *game, char **map);
void	display_map(t_game *game);

#endif
