/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 18:21:05 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/06 18:21:08 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			new;
	int			neg;

	neg = 0;
	i = 0;
	new = 0;
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == 0)
		return (0);
	neg = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((char)str[i] < '0' || (char)str[i] > '9')
			break ;
		new *= 10;
		new += str[i] - 48;
		i++;
	}
	if (str[neg] == '-')
		return (-new);
	return (new);
}

char			*ft_strdup(char *str)
{
	int			i;
	char		*new;

	i = 0;
	new = NULL;
	if (str == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
