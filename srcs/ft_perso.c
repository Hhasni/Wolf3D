/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 20:40:47 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/14 20:40:53 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int			ft_perso_auto(t_env *e)
{
	int				i;
	int				l;

	l = 0;
	while (l < e->nb_line)
	{
		i = 0;
		while (i < e->size_line)
		{
			if (e->map[l][i] == 0)
			{
				if (e->map[l][i] == 0)
				{
					e->posy = i + 0.1;
					e->posx = l + 0.1;
					return (1);
				}
			}
			i++;
		}
		l++;
	}
	return (-1);
}

void				ft_perso(t_env *e)
{
	int				i;
	int				l;

	l = 0;
	while (l < e->nb_line)
	{
		i = 0;
		while (i < e->size_line)
		{
			if (e->map[l][i] == 7)
			{
				e->posy = i + 0.1;
				e->posx = l + 0.1;
				return ;
			}
			i++;
		}
		l++;
	}
	if (ft_perso_auto(e) == -1)
	{
		ft_error(5);
		exit(5);
	}
}
