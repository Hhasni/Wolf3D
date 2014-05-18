/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:53:12 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/09 15:53:13 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void				ft_moveforward(t_env *e)
{
	if (e->map[(int)(e->posx + e->dirx * MOVE_SPEED)][(int)(e->posy)] == 0
		|| e->map[(int)(e->posx + e->dirx * MOVE_SPEED)][(int)(e->posy)] == 7)
		e->posx = e->posx + e->dirx * MOVE_SPEED;
	if (e->map[(int)(e->posx)][(int)(e->posy + e->diry * MOVE_SPEED)] == 0
		|| e->map[(int)(e->posx + e->dirx * MOVE_SPEED)][(int)(e->posy)] == 7)
		e->posy = e->posy + e->diry * MOVE_SPEED;
}

static void			ft_movebackyard(t_env *e)
{
	if (e->map[(int)(e->posx - e->dirx * MOVE_SPEED)][(int)(e->posy)] == 0
		|| e->map[(int)(e->posx + e->dirx * MOVE_SPEED)][(int)(e->posy)] == 7)
		e->posx = e->posx - e->dirx * MOVE_SPEED;
	if (e->map[(int)(e->posx)][(int)(e->posy - e->diry * MOVE_SPEED)] == 0
		|| e->map[(int)(e->posx + e->dirx * MOVE_SPEED)][(int)(e->posy)] == 7)
		e->posy = e->posy - e->diry * MOVE_SPEED;
}

void				ft_turn_left(t_env *e)
{
	double		tmp1;
	double		tmp2;

	tmp1 = e->dirx;
	tmp2 = e->planx;
	e->dirx = e->dirx * cos(ROT_SPEED) - e->diry * sin(ROT_SPEED);
	e->diry = tmp1 * sin(ROT_SPEED) + e->diry * cos(ROT_SPEED);
	e->planx = e->planx * cos(ROT_SPEED) - e->plany * sin(ROT_SPEED);
	e->plany = tmp2 * sin(ROT_SPEED) + e->plany * cos(ROT_SPEED);
}

void				ft_turn_right(t_env *e)
{
	double		tmp1;
	double		tmp2;

	tmp1 = e->dirx;
	tmp2 = e->planx;
	e->dirx = e->dirx * cos(-ROT_SPEED) - e->diry * sin(-ROT_SPEED);
	e->diry = tmp1 * sin(-ROT_SPEED) + e->diry * cos(-ROT_SPEED);
	e->planx = e->planx * cos(-ROT_SPEED) - e->plany * sin(-ROT_SPEED);
	e->plany = tmp2 * sin(-ROT_SPEED) + e->plany * cos(-ROT_SPEED);
}

void				ft_move_even(int keycode, t_env *e)
{
	if (keycode == UP || keycode == W)
		ft_moveforward(e);
	else if (keycode == DOWN || keycode == S)
		ft_movebackyard(e);
	else if (keycode == LEFT || keycode == A)
		ft_turn_left(e);
	else if (keycode == RIGHT || keycode == D)
		ft_turn_right(e);
	else if (keycode == Q)
		ft_straffe_left(e);
	else if (keycode == E)
		ft_straffe_right(e);
	else if (keycode == 65289)
		ft_left(e);
	else if (keycode == 114)
		ft_right(e);
}
