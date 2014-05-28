/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:53:12 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/28 20:11:18 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void				ft_moveforward(t_env *e)
{
	if (e->map[(int)(e->posx + e->dirx * e->move_s)][(int)(e->posy)] == 0
		|| e->map[(int)(e->posx + e->dirx * e->move_s)][(int)(e->posy)] == 7)
		e->posx = e->posx + e->dirx * e->move_s;
	if (e->map[(int)(e->posx)][(int)(e->posy + e->diry * e->move_s)] == 0
		|| e->map[(int)(e->posx + e->dirx * e->move_s)][(int)(e->posy)] == 7)
		e->posy = e->posy + e->diry * e->move_s;
}

void				ft_movebackyard(t_env *e)
{
	if (e->map[(int)(e->posx - e->dirx * e->move_s)][(int)(e->posy)] == 0
		|| e->map[(int)(e->posx + e->dirx * e->move_s)][(int)(e->posy)] == 7)
		e->posx = e->posx - e->dirx * e->move_s;
	if (e->map[(int)(e->posx)][(int)(e->posy - e->diry * e->move_s)] == 0
		|| e->map[(int)(e->posx + e->dirx * e->move_s)][(int)(e->posy)] == 7)
		e->posy = e->posy - e->diry * e->move_s;
}

void				ft_turn_left(t_env *e)
{
	double			tmp1;
	double			tmp2;

	tmp1 = e->dirx;
	tmp2 = e->planx;
	e->dirx = e->dirx * cos(ROT_SPEED + e->rot_s)
		- e->diry * sin(ROT_SPEED + e->rot_s);
	e->diry = tmp1 * sin(ROT_SPEED + e->rot_s)
		+ e->diry * cos(ROT_SPEED + e->rot_s);
	e->planx = e->planx * cos(ROT_SPEED + e->rot_s)
		- e->plany * sin(ROT_SPEED + e->rot_s);
	e->plany = tmp2 * sin(ROT_SPEED + e->rot_s)
		+ e->plany * cos(ROT_SPEED + e->rot_s);
}

void				ft_turn_right(t_env *e)
{
	double			tmp1;
	double			tmp2;

	tmp1 = e->dirx;
	tmp2 = e->planx;
	e->dirx = e->dirx * cos(-(ROT_SPEED + e->rot_s))
		- e->diry * sin(-(ROT_SPEED + e->rot_s));
	e->diry = tmp1 * sin(-(ROT_SPEED + e->rot_s))
		+ e->diry * cos(-(ROT_SPEED + e->rot_s));
	e->planx = e->planx * cos(-(ROT_SPEED + e->rot_s))
		- e->plany * sin(-(ROT_SPEED + e->rot_s));
	e->plany = tmp2 * sin(-(ROT_SPEED + e->rot_s))
		+ e->plany * cos(-(ROT_SPEED + e->rot_s));
}
