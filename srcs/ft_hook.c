/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:45:04 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 15:33:57 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int					key_hook(int keycode, t_env *e)
{
	ft_move_even(keycode, e);
	if (keycode == 61)
		e->coeffcam = 1.1;
	else if (keycode == 122)
	{
		if (e->dark == 0)
			e->dark = 1;
		else
			e->dark = 0;
	}
	else if (keycode == 45)
		e->coeffcam = 2;
	else if (keycode == 32)
	{
		e->planx += 0.2;
		e->plany += 0.2;
	}
	if (keycode == 65307)
		exit(0);
	ft_hook(e);
	return (0);
}

int					mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		ft_destroy_block(e, x, y);
	if (button == 3)
		ft_add_block(e, x, y);
	return (0);
}

int					expose_hook(t_env *e)
{
	ft_hook(e);
	return (0);
}

int					ft_hook(t_env *e)
{
	e->x = 0;
	if (e->dark > 0)
	{
		while (e->x < WIDTH)
		{
			e->draws = 0;
			e->drawe = HEIGH / 2;
			e->color = 0x000000;
			ft_draw(e);
			e->draws = HEIGH / 2;
			e->drawe = HEIGH;
			e->color = 0x000000;
			ft_draw(e);
			e->x++;
		}
	}
	ft_ray(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_put_image_to_window
		(e->mlx, e->win, e->gun, (WIDTH / 3) * 2, HEIGH - 378);
	return (0);
}
