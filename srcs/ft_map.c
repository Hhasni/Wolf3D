/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 15:37:02 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/09 15:38:19 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int					ft_count(char *line)
{
	int				ret;
	int				i;

	i = 0;
	ret = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			i++;
			ret++;
		}
		else
			i++;
	}
	return (ret);
}

int					ft_recover_map(t_list **list)
{
	int				fd;
	char			*line;
	int				len;

	len = 0;
	line = NULL;
	if ((fd = open("natchderuntoten", O_RDONLY | S_IRUSR)) == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		len++;
		ft_fill_map_specs(list, line, len, ft_count(line));
	}
	if (close(fd) == -1)
		return (-1);
	return (len);
}

int					**ft_fill_tab(t_list *list, int **map)
{
	char			**tmp_tab;
	int				i;
	int				l;

	tmp_tab = NULL;
	l = 0;
	while (list)
	{
		i = 0;
		tmp_tab = ft_strsplit(list->line, ' ');
		while (tmp_tab[i])
		{
			map[l][i] = ft_atoi(tmp_tab[i]);
			i++;
		}
		l++;
		list = list->next;
	}
	return (map);
}

int					**ft_map(t_env *e)
{
	t_list			*list;
	int				**map;
	int				len;
	int				i;

	i = 0;
	list = NULL;
	map = NULL;
	if ((len = ft_recover_map(&list)) == -1)
		return (NULL);
	e->nb_line = len;
	e->size_line = list->size_line;
	if (!(map = (int **)malloc(sizeof(int *) * len)))
		return (NULL);
	while (i < len)
	{
		if (!(map[i++] = (int *)malloc(sizeof(int) * list->size_line)))
			return (NULL);
	}
	return (ft_fill_tab(list, map));
}
