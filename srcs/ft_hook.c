/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:45:04 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/28 20:10:24 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>

int					mouse_hook(int button, int x, int y, t_env *e)
{
	printf("HEY y = <%d>\n", y);
	e->cursor = y;
	if (button == 1)
		ft_destroy_block(e, x, y);
	if (button == 3)
		ft_add_block(e, x, y);
	return (0);
}
/*
// void				ft_mouse_move(t_env *e)
// {
// 	mlx_mouse_hook(e->win , mouse_hook, &e);
// 	printf("e->cursor = <%f>\n", e->cursor);
// 	if (e->cursor < -20)
// 		ft_turn_left(e);
// 	if (e->cursor > 20)
// 		ft_turn_right(e);
// }
*/
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

int					ft_loop_hook(t_env *e)
{
	if (e->moveforward)
		ft_moveforward(e);
	if (e->movebackyard)
		ft_movebackyard(e);
	if (e->turn_left)
		ft_turn_left(e);
	if (e->turn_right)
		ft_turn_right(e);
	if (e->straffe_right)
		ft_straffe_right(e);
	if (e->straffe_left)
		ft_straffe_left(e);
	if (e->left)
		ft_left(e);
	if (e->right)
		ft_right(e);
	expose_hook(e);
	return (0);
}
