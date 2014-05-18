/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dark_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 14:41:43 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 14:42:05 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			ft_dark_mode(t_env *e)
{
	if (e->x >= (10 * WIDTH) / 100 && e->x <= (90 * WIDTH / 100))
	{
		if (e->pwdist < 5 && (e->x < (30 * WIDTH) / 100
					|| e->x > (70 * WIDTH / 100)))
			ft_draw_dark(e);
		else if (e->pwdist < 3)
			ft_draw(e);
		else if (e->pwdist < 5)
			ft_draw_dark(e);
	}
}

void			ft_draw_dark(t_env *e)
{
	int			in;
	int			i;
	int			d;

	d = 0;
	i = 0;
	if ((e->x % 2) == 1)
	{
		while (e->draws < e->drawe)
		{
			in = (e->bpp >> 3) * (((int)e->draws
						* (e->sizel >> 2)) + (int)e->x);
			if (d == 1)
				d = 0;
			if (d == 0)
			{
				e->str[in] = 0x333333 & 0xff;
				e->str[in + 1] = (0x333333 & 0xff00) >> 8;
				e->str[in + 2] = (0x333333 & 0xff0000) >> 16;
				e->draws += 4;
				d = 1;
			}
		}
	}
}
