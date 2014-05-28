/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 10:31:47 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/28 20:10:57 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include </usr/X11/include/X11/X.h>
# define BUFF_SIZE	256
# define HEIGH		720
# define WIDTH		1280
# define UP			65362
# define W			119
# define DOWN		65364
# define S			115
# define LEFT		65361
# define A			97
# define RIGHT		65363
# define D			100
# define Q			113
# define E			101
# define MOVE_SPEED 0.05
# define ROT_SPEED	0.05
# define NB_TEXTURES 2
# define TEXW 64
# define TEXH 64

typedef struct		s_env
{
	int				**map;
	void			*mlx;
	void			*win;
	void			*img;
	void			*test;
	void			*gun;
	int				size_line;
	int				nb_line;
	int				sizel;
	int				endian;
	int				bpp;
	char			*str;
	char			*gundata;

	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;

	int				x;
	double			camera;
	double			rposx;
	double			rposy;
	double			rdirx;
	double			rdiry;
	int				mapx;
	int				mapy;

	double			sidedistx;
	double			sidedisty;
	double			ddistx;
	double			ddisty;
	double			pwdist;
	int				hit;
	int				stepx;
	int				stepy;
	int				side;

	int				lineheight;
	int				draws;
	int				drawe;
	int				color;
	int				ray_tex;

	double			coeffcam;
	double			dark;
	double			move_s;
	int				moveforward;
	int				movebackyard;
	int				turn_left;
	int				turn_right;
	int				straffe_right;
	int				straffe_left;
	int				left;
	int				right;
	double			rot_s;
	double			cursor;

}					t_env;

typedef struct		s_list
{
	int				line_nbr;
	int				size_line;
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct		s_mini
{
	int				x;
	int				y;
	int				l;
	int				i;
	int				c;
	int				t;
	int				z;
	int				color;
}					t_mini;

int					ft_error(int e);
int					ft_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
void				ft_draw(t_env *e);
int					**ft_map(t_env *e);
char				**ft_strsplit(char *str, char c);
int					ft_strlen(char *s);
int					ft_atoi(const char *str);
char				*ft_strdup(char *str);
void				ft_ray(t_env *e);
int					get_next_line(int const fd, char **line);
void				ft_fill_map_specs(t_list **l, char *line, int i, int size);
void				ft_initray(t_env *e);
void				ft_dda(t_env *e);
void				ft_line(t_env *e);
void				ft_moveforward(t_env *e);
void				ft_movebackyard(t_env *e);
void				ft_turn_left(t_env *e);
void				ft_turn_right(t_env *e);
void				ft_straffe_left(t_env *e);
void				ft_straffe_right(t_env *e);
void				ft_left(t_env *e);
void				ft_right(t_env *e);
void				ft_tex(t_env *e);
void				ft_draw_dark(t_env *e);
void				ft_dark_mode(t_env *e);
void				ft_perso(t_env *e);
void				ft_move_even(int keycode, t_env *e);
void				ft_destroy_block(t_env *e, int x, int y);
void				ft_add_block(t_env *e, int x, int y);
int					ft_key_press(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
int					ft_loop_hook(t_env *e);

#endif
