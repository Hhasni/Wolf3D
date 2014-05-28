/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 20:05:58 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/28 20:20:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void				ft_key_move(int keycode, t_env *e)
{
	if (keycode == UP || keycode == W)
		e->moveforward = 1;
	else if (keycode == DOWN || keycode == S)
		e->movebackyard = 1;
	else if (keycode == LEFT || keycode == A)
		e->turn_left = 1;
	else if (keycode == RIGHT || keycode == D)
		e->turn_right = 1;
	else if (keycode == Q)
		e->straffe_left = 1;
	else if (keycode == E)
		e->straffe_right = 1;
	else if (keycode == 49)
		e->left = 1;
	else if (keycode == 51)
		e->right = 1;
}

int					ft_key_press(int keycode, t_env *e)
{
	ft_key_move(keycode, e);
	if (keycode == 65505)
		e->move_s = 0.13;
	else if (keycode == 65289)
		e->move_s = 0.02;
	else if (keycode == 65453 && (e->rot_s > -0.04))
		e->rot_s -= 0.01;
	else if (keycode == 65451 && (e->rot_s < 0.17))
		e->rot_s += 0.01;
	else if (keycode == 65421)
		e->rot_s = 0;
	else if (keycode == 61)
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
	else if (keycode == 65307)
		exit(0);
	return (0);
}

int					ft_key_release(int keycode, t_env *e)
{
	if (keycode == UP || keycode == W)
		e->moveforward = 0;
	else if (keycode == DOWN || keycode == S)
		e->movebackyard = 0;
	else if (keycode == LEFT || keycode == A)
		e->turn_left = 0;
	else if (keycode == RIGHT || keycode == D)
		e->turn_right = 0;
	else if (keycode == Q)
		e->straffe_left = 0;
	else if (keycode == E)
		e->straffe_right = 0;
	else if (keycode == 49)
		e->left = 0;
	else if (keycode == 51)
		e->right = 0;
	else if (keycode == 65505 || keycode == 65289)
		e->move_s = MOVE_SPEED;
	else if (keycode == 65307)
		exit(0);
	return (0);
}
