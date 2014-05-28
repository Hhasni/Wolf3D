/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straffe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 14:44:11 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 15:12:30 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_straffe_left(t_env *e)
{
	if (e->dirx >= -1 && e->dirx <= -0.8 && e->diry > -0.8 && e->diry <= 0.8)
	{
		if (e->map[(int)(e->posx)][(int)(e->posy - e->move_s)] == 0
			&& e->map[(int)(e->posx)][(int)(e->posy - e->move_s)] == 0)
			e->posy = e->posy - e->move_s;
	}
	else if (e->dirx >= 0.5 && e->dirx <= 1 && e->diry >= -0.8 && e->diry < 0.8)
	{
		if (e->map[(int)(e->posx)][(int)(e->posy + e->move_s)] == 0
			&& e->map[(int)(e->posx)][(int)(e->posy + e->move_s)] == 0)
			e->posy = e->posy + e->move_s;
	}
	else if (e->dirx >= -0.8 && e->dirx <= 0.8
		&& e->diry >= -1 && e->diry < -0.5)
	{
		if (e->map[(int)(e->posx + e->move_s)][(int)(e->posy)] == 0)
			e->posx = e->posx + e->move_s;
	}
	else if (e->dirx >= -0.8 && e->dirx <= 0.8 && e->diry > 0.5 && e->diry <= 1)
	{
		if (e->map[(int)(e->posx - e->move_s)][(int)(e->posy)] == 0)
			e->posx = e->posx - e->move_s;
	}
}

void		ft_straffe_right(t_env *e)
{
	if (e->dirx >= -1 && e->dirx <= -0.8 && e->diry > -0.8 && e->diry <= 0.8)
	{
		if (e->map[(int)(e->posx)][(int)(e->posy + e->move_s)] == 0
			&& e->map[(int)(e->posx)][(int)(e->posy + e->move_s)] == 0)
			e->posy = e->posy + e->move_s;
	}
	else if (e->dirx >= 0.5 && e->dirx <= 1 && e->diry >= -0.8 && e->diry < 0.8)
	{
		if (e->map[(int)(e->posx)][(int)(e->posy - e->move_s)] == 0
			&& e->map[(int)(e->posx)][(int)(e->posy - e->move_s)] == 0)
			e->posy = e->posy - e->move_s;
	}
	else if (e->dirx >= -0.8 && e->dirx <= 0.8
		&& e->diry >= -1 && e->diry < -0.5)
	{
		if (e->map[(int)(e->posx - e->move_s)][(int)(e->posy)] == 0)
			e->posx = e->posx - e->move_s;
	}
	else if (e->dirx >= -0.8 && e->dirx <= 0.8 && e->diry > 0.5 && e->diry <= 1)
	{
		if (e->map[(int)(e->posx + e->move_s)][(int)(e->posy)] == 0)
			e->posx = e->posx + e->move_s;
	}
}

void		ft_left(t_env *e)
{
	ft_moveforward(e);
	ft_turn_left(e);
}

void		ft_right(t_env *e)
{
	ft_moveforward(e);
	ft_turn_right(e);
}
