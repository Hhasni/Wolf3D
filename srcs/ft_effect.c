/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 20:26:04 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 20:26:09 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void				ft_destroy_and_recoil(t_env *e, int y)
{
	int					i;

	i = 0;
	while (i < 5)
	{
		if (e->map[e->mapx][e->mapy] == 2 && y > e->draws && y < e->drawe)
			e->map[e->mapx][e->mapy] = 0;
		if (e->map[(int)(e->posx - e->dirx * 0.1)][(int)(e->posy)] == 0)
			e->posx = e->posx - e->dirx * 0.1;
		if (e->map[(int)(e->posx)][(int)(e->posy - e->diry * 0.1)] == 0)
			e->posy = e->posy - e->diry * 0.1;
		i++;
		ft_hook(e);
		usleep (1000);
	}
}

static void				ft_do_adding(t_env *e, int y)
{
	if (e->side == 0 && (e->map[e->mapx][e->mapy] == 1
		|| e->map[e->mapx][e->mapy] == 2) && ((e->mapx - 1) != (int)e->posx
		|| e->mapy != (int)e->posy) && (y > e->draws && y < e->drawe))
		e->map[e->mapx - 1][e->mapy] = 2;
	if (e->side == 2 && (e->map[e->mapx][e->mapy] == 1
		|| e->map[e->mapx][e->mapy] == 2) && (e->mapx != (int)e->posx
		|| (e->mapy - 1) != (int)e->posy) && (y > e->draws && y < e->drawe))
		e->map[e->mapx][e->mapy - 1] = 2;
	if (e->side == 1 && (e->map[e->mapx][e->mapy] == 1
		|| e->map[e->mapx][e->mapy] == 2) && ((e->mapx + 1) != (int)e->posx
		|| e->mapy != (int)e->posy) && (y > e->draws && y < e->drawe))
		e->map[e->mapx + 1][e->mapy] = 2;
	if (e->side == 3 && (e->map[e->mapx][e->mapy] == 1
		|| e->map[e->mapx][e->mapy] == 2) && (e->mapx != (int)e->posx
		|| (e->mapy + 1) != (int)e->posy) && (y > e->draws && y < e->drawe))
		e->map[e->mapx][e->mapy + 1] = 2;
}

void					ft_add_block(t_env *e, int x, int y)
{
	e->x = x;
	ft_initray(e);
	if (e->rdirx < 0)
		e->sidedistx = (e->rposx - e->mapx) * e->ddistx;
	else
		e->sidedistx = (e->mapx + 1.0 - e->rposx) * e->ddistx;
	if (e->rdiry < 0)
		e->sidedisty = (e->rposy - e->mapy) * e->ddisty;
	else
		e->sidedisty = (e->mapy + 1.0 - e->rposy) * e->ddisty;
	ft_dda(e);
	ft_line(e);
	ft_do_adding(e, y);
	ft_hook(e);
}

void					ft_destroy_block(t_env *e, int x, int y)
{
	e->x = x;
	ft_initray(e);
	if (e->rdirx < 0)
		e->sidedistx = (e->rposx - e->mapx) * e->ddistx;
	else
		e->sidedistx = (e->mapx + 1.0 - e->rposx) * e->ddistx;
	if (e->rdiry < 0)
		e->sidedisty = (e->rposy - e->mapy) * e->ddisty;
	else
		e->sidedisty = (e->mapy + 1.0 - e->rposy) * e->ddisty;
	ft_dda(e);
	ft_line(e);
	ft_destroy_and_recoil(e, y);
	ft_hook(e);
}
