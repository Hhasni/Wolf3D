/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:37:58 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 21:21:11 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			ft_draw_sky(t_env *e, int color)
{
	int			i;
	int			in;

	i = 0;
	while (i < (e->draws - 2))
	{
		in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
		e->str[in] = color & 0xff;
		e->str[in + 1] = (color & 0xff00) >> 8;
		e->str[in + 2] = (color & 0xff0000) >> 16;
		i++;
	}
	while (i < e->draws)
	{
		in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
		e->str[in] = 0x000000 & 0xff;
		e->str[in + 1] = (0x000000 & 0xff00) >> 8;
		e->str[in + 2] = (0x000000 & 0xff0000) >> 16;
		i++;
	}
}

void			ft_draw_ground(t_env *e, int color)
{
	int			i;
	int			in;

	i = e->drawe;
	while (i < (e->drawe + 2))
	{
		in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
		e->str[in] = 0x000000 & 0xff;
		e->str[in + 1] = (0x000000 & 0xff00) >> 8;
		e->str[in + 2] = (0x000000 & 0xff0000) >> 16;
		i++;
	}
	while (i < HEIGH)
	{
		in = (e->bpp >> 3) * (((int)i * (e->sizel >> 2)) + (int)e->x);
		e->str[in] = color & 0xff;
		e->str[in + 1] = (color & 0xff00) >> 8;
		e->str[in + 2] = (color & 0xff0000) >> 16;
		i++;
	}
}

void			ft_draw(t_env *e)
{
	int			in;

	if (!e->dark)
		ft_draw_sky(e, 0x19B5FE);
	while (e->draws < e->drawe)
	{
		in = (e->bpp >> 3) * (((int)e->draws * (e->sizel >> 2)) + (int)e->x);
		e->str[in] = e->color & 0xff;
		e->str[in + 1] = (e->color & 0xff00) >> 8;
		e->str[in + 2] = (e->color & 0xff0000) >> 16;
		e->draws++;
	}
	if (!e->dark)
		ft_draw_ground(e, 0x222222);
}
