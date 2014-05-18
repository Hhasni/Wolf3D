/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:54:45 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 14:43:57 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_initray(t_env *e)
{
	e->camera = (2 * e->x / (double)WIDTH - 1);
	e->rposx = e->posx;
	e->rposy = e->posy;
	e->rdirx = e->dirx + e->planx * e->camera;
	e->rdiry = e->diry + e->plany * e->camera;
	e->mapx = (int)e->rposx;
	e->mapy = (int)e->rposy;
	e->ddistx = sqrt(1 + (e->rdiry * e->rdiry) / (e->rdirx * e->rdirx));
	e->ddisty = sqrt(1 + (e->rdirx * e->rdirx) / (e->rdiry * e->rdiry));
	e->hit = 0;
	if (e->rdirx < 0)
		e->stepx = -1;
	else
		e->stepx = 1;
	if (e->rdiry < 0)
		e->stepy = -1;
	else
		e->stepy = 1;
}

void		ft_dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->ddistx;
			e->mapx += e->stepx;
			e->side = 0;
			if (e->stepx == -1)
				e->side = 1;
		}
		else
		{
			e->sidedisty += e->ddisty;
			e->mapy += e->stepy;
			e->side = 2;
			if (e->stepy == -1)
				e->side = 3;
		}
		if (e->map[e->mapx][e->mapy] > 0 && e->map[e->mapx][e->mapy] != 7)
			e->hit = 1;
	}
	if (e->side == 0 || e->side == 1)
		e->pwdist = fabs((e->mapx - e->rposx + (1 - e->stepx) / 2) / e->rdirx);
	else
		e->pwdist = fabs((e->mapy - e->rposy + (1 - e->stepy) / 2) / e->rdiry);
}

void		ft_line(t_env *e)
{
	e->lineheight = abs((int)(HEIGH / e->pwdist));
	if (e->coeffcam != 2)
		e->draws = -(e->lineheight) / e->coeffcam + HEIGH / e->coeffcam;
	else
		e->draws = -(e->lineheight) / 2 + HEIGH / 2;
	if (e->draws < 0)
		e->draws = 0;
	if (e->coeffcam != 2)
		e->drawe = (e->lineheight) / e->coeffcam + HEIGH / e->coeffcam;
	else
		e->drawe = (e->lineheight) / 2 + HEIGH / 2;
	if (e->drawe >= HEIGH)
		e->drawe = HEIGH - 1;
}

void		ft_color(t_env *e)
{
	if (e->map[e->mapx][e->mapy] == 1)
		e->color = 0xD91E18;
	else if (e->map[e->mapx][e->mapy] == 2)
		e->color = 0xEF4836;
	else
		e->color = 0xD64541;
	if (e->side == 1)
		e->color -= 200;
	else if (e->side == 2)
		e->color += 200;
	else if (e->side == 3)
		e->color += 400;
}

void		ft_ray(t_env *e)
{
	e->x = 0;
	while (e->x < WIDTH)
	{
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
		ft_color(e);
		if (e->dark == 1)
			ft_dark_mode(e);
		else
			ft_draw(e);
		e->x++;
	}
}
