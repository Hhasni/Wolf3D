/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 18:20:50 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/06 18:20:53 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int		ft_count_words(char *str, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c || str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] != c && str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
		j++;
	}
	return (j);
}

char			*ft_strdup_to_end(char *str, int s, int e)
{
	int			i;
	int			len;
	char		*new;

	i = 0;
	len = e - s;
	str = &str[s];
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s < e)
	{
		new[i] = str[i];
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}

char			**ft_strsplit(char *str, char c)
{
	int			i;
	int			j;
	int			k;
	char		**new;

	i = 0;
	j = 0;
	if (!(new = (char **)malloc(sizeof(char *) * ft_count_words(str, c) + 1)))
		return (NULL);
	while (str[i])
	{
		while (str[i] == c || str[i] == ' ' || str[i] == '\t')
			i++;
		k = i;
		while (str[i] != c && str[i] != ' ' && str[i] != '\t' && str[i])
			i++;
		new[j] = ft_strdup_to_end(str, k, i);
		if (*new[j] != '\0')
			j++;
	}
	new[j] = NULL;
	return (new);
}
