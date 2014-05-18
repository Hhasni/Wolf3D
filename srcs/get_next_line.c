/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 17:38:04 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/06 18:21:15 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static char		*ft_strcat(char *s1, char *s2)
{
	int			i;
	int			j;
	int			len;
	char		*new;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
			new[i++] = s2[j++];
	}
	new[i] = '\0';
	return (new);
}

static int		ft_search_n_save(char *bkp, char **tmp, char **line)
{
	int			i;

	i = 0;
	while (bkp[i] != '\0')
	{
		if (bkp[i] == '\n' || bkp[i + 1] == 26)
		{
			bkp[i++] = '\0';
			*tmp = NULL;
			*tmp = ft_strdup(&bkp[i]);
			*line = ft_strdup(bkp);
			free(bkp);
			bkp = NULL;
			return (1);
		}
		i++;
	}
	*tmp = NULL;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*tmp = "";
	char		*bkp;
	char		*buff;
	int			ret;

	bkp = NULL;
	buff = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || tmp)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		bkp = ft_strcat(bkp, tmp);
		bkp = ft_strcat(bkp, buff);
		if (ft_search_n_save(bkp, &tmp, line) == 1)
			return (1);
	}
	if (bkp && *bkp && ret == 0)
	{
		*line = ft_strdup(bkp);
		return (1);
	}
	return (0);
}
