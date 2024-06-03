/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:41:36 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 12:50:26 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ctword(const char *src, char c)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] != c)
		{
			ct++;
			while (src[i] && src[i] != c)
				i++;
		}
		else
			i++;
	}
	return (ct + 1);
}

char	**freetab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*remplist(const char *src, char c)
{
	int		i;
	char	*l;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	l = (char *)malloc(i + 1);
	if (l == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		l[i] = src[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	int		i;
	int		j;

	d = ((char **)malloc((sizeof(char *) * ctword(s, c))));
	if (s == 0 || (!d))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			d[j] = remplist(s + i, c);
			if (d[j] == NULL)
				return (freetab(d, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	d[j] = 0;
	return (d);
}
