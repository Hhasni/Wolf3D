/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 23:03:25 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/09 15:38:11 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_fill_map_specs(t_list **l, char *line, int i, int size)
{
	t_list	*tmp;
	t_list	*new;

	tmp = NULL;
	new = NULL;
	if (!(new = malloc(sizeof(t_list))))
		return ;
	new->line = ft_strdup(line);
	new->line_nbr = i;
	new->size_line = size;
	new->next = NULL;
	tmp = *l;
	if (tmp == NULL)
		*l = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
