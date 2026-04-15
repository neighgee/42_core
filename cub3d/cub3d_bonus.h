/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:37:59 by smariapp          #+#    #+#             */
/*   Updated: 2026/04/11 20:22:23 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "fcntl.h"
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>

typedef struct s_params
{
	char		*n;
	char		*s;
	char		*e;
	char		*w;
	int			textures;
	int			ceil;
	int			floor;
	int			colours;
	char		**map;
	t_list		*maplist;
	char		dir;
	int			fd;
}	t_params;

/* Struct is to store player's pov:
1.Player's position on the map is calculated
2.Player's direction is fixed at the start then varies
3.Camera plane or cam_x and cam_y:
	-perpendicular to direction vector
	-usually 0.66 to show enough of the surroundings
	((Field of Vision ^)) */
typedef struct s_pov
{
	double	playerx;
	double	playery;
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;
}	t_pov;

/* Struct is to store ray casting variables for calculation
Values in double represent the exact position
Values in int represent the values in cells/tiles/yes/no */
typedef struct s_ray
{
	double	r_vs_cam; //to check how left/right it is on cam
	double	ray_dirx; //which horizontal direction
	double	ray_diry; //which vertical direction
	int		map_x; //same as playerx but in int
	int		map_y; //same as playery but in int
	double	deltadistx; //distance from 1X to another
	double	deltadisty; //distance from 1Y to another
	double	perpwalldist; //wall's distance
	double	total_x; //distance from ray's origin to the next x
	double	total_y; //distance from ray's origin to the next y
	int		step_x; //ray's direction in x (aka left/right)
	int		step_y; //ray's direction in y (aka up/down)
	int		wall; //1 if hits wall, 0 if no wall
	int		hit_y; //1 if hit y, 0 if hit x
}	t_ray;

/* Struct just helps to draw walls correctly */
typedef struct s_wall
{
	int	wallheight;
	int	topypixel;
	int	endypixel;
}	t_wall;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

/* Minimap is structured so that it centres the player
It shows only a specific number of tiles around player
This is incase of huge maps, to prevent huge minimaps */
typedef struct s_minimap
{
	int	first_x;
	int	first_y;
	int	tile_size; //pixels of 1 tile on minimap
	int	radius; //no. of tiles around the player on minimap
	int	player_pixel; //player in pixels (how big on minimap)
	int	wall_c;
	int	floor_c;
	int	player_c;
	int	dir_c;
}	t_minimap;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

/* Endian helps you to keep track of how color bytes are ordered
Your system might store it differently so this is just to be safe
Needed for correct  byte interpretation of color data */
typedef struct s_screen
{
	void	*img; //image object by MLX
	char	*addr; //address of the pixel buffer
	int		bpp; //just to calculate how many bits is needed per pixel
	int		b_perline; //bytes in one row of image (taken from MLX)
	int		endian; //data on how bytes are arranged (taken from MLX)
}	t_screen;

typedef struct s_textures
{
	void	*img;
	char	*addr;
	int		bpp;
	int		b_perline;
	int		endian;
	int		width;
	int		height;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_params	*par;
	t_screen	screen;
	t_map		map;
	t_minimap	mini_map;
	t_pov		player;
	t_ray		ray;
	t_wall		wall;
	t_keys		keys;
	t_textures	n;
	t_textures	s;
	t_textures	e;
	t_textures	w;
}	t_game;

void		free_arr(char **arr);
void		free_params(t_params *par);
int			check_file_type(char *file, char *type);
int			ft_arrlen(char **arr);
int			gimme_fd(char *file);

void		check_textures(char *str, t_params *par);
void		check_colours(char *str, t_params *par, int cf);

char		**map_create(t_list *file);
int			map_check(t_params *par);
int			map_s(t_list *file);

t_params	*parse_file(int fd);

int			identifier(char	*line);

//Initialise
int			init_win(t_game *game);
void		init_minimap(t_game *game);
void		init_map(t_game *game);
int			init_player(t_game *game);
int			init_game(t_game *game);
void		create_textures(t_game *game, t_textures *tex, char *path);
void		init_textures(t_game *game);

//Colour pixels
void		colour_pixels(t_screen *screen, int x, int y, int colour);
void		colour_minimap(t_game *game, int firstx, int firsty, int colour);
void		colour_player(t_game *game, int firstx, int firsty, int colour);
void		colour_f_c(t_game *game);
int			return_pixel_colour(t_textures	*tex, int x, int y);
int			find_tex_x(t_game *game, t_textures *tex);
t_textures	*choose_texture(t_game *game);

//Raycasting & its utils
void		raycasting(t_game *game);
void		draw_wall(t_game *game, int x);

//Minimap
void		minimap(t_game *game);

//Movement
void		listen_to_events(t_game *game);
void		walk_updown(t_game *game);
void		turn_sideway(t_game *game);

//Cleanups
void		clean_program(t_game *game);
int			quit_program(t_game *game);

#endif
