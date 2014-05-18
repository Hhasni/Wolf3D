/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 16:12:21 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 15:19:38 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void				ft_mlx_gun(t_env *e)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	if (!(e->gun = mlx_xpm_file_to_image(e->mlx, "img/gun.xpm", &x, &y)))
		exit((ft_error(-1)));
	if (!(e->gundata = mlx_get_data_addr(e->gun, &(e->bpp),
		&(e->sizel), &(e->endian))))
		exit((ft_error(-1)));
}

int					ft_error(int e)
{
	if (e == 0)
		write(1, "ERROR please type ./wolf3d\n",
			ft_strlen("ERROR please type ./wolf3d\n"));
	else if (e == 1)
		write(1, "\033[1;31mFuck you son of a bitch\n\033[0m",
			ft_strlen("\033[1;31mFuck you son of a bitch\n\033[0m"));
	else if (e == 2)
		write(1, "ERROR map failed to build\n",
			ft_strlen("ERROR map failed to build\n"));
	else if (e == 3)
		write(1, "ERROR image failed to build\n",
			ft_strlen("ERROR image failed to build\n"));
	else if (e == 4)
		write(1, "ERROR gun failed to pack a punch\n",
			ft_strlen("ERROR gun failed to pack a punch\n"));
	else if (e == 5)
		write(1, "ERROR no Walthrouable case\n",
			ft_strlen("ERROR no Walthrouable case\n"));
	return (e);
}

void				ft_val(t_env *e)
{
	int				i;

	i = 0;
	ft_perso(e);
	e->coeffcam = 2;
	e->dirx = -1;
	e->diry = 0;
	e->planx = 0;
	e->plany = 0.66;
}

int					main(int ac, char **av, char **env)
{
	t_env			e;

	(void)av;
	if (ac != 1)
		return (ft_error(0));
	if (!(env[0]))
		return (ft_error(1));
	if (!(e.map = ft_map(&e)))
		return (ft_error(2));
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGH, "WOLF3D");
	if (!(e.img = mlx_new_image(e.mlx, WIDTH, HEIGH)))
		return (ft_error(3));
	ft_mlx_gun(&e);
	if (!(e.str = mlx_get_data_addr
				(e.img, &(e.bpp), &(e.sizel), &(e.endian))))
		return (ft_error(3));
	ft_val(&e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, ft_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
