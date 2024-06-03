/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:58:28 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 15:45:58 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freelist(char **l, char **l2)
{
	int	i;

	i = 0;
	while (l[i] != NULL)
		free(l[i++]);
	free(l);
	i = 0;
	while (l2[i] != NULL)
		free(l2[i++]);
	free(l2);
}

int	filllist(char **r, char **g, int i, int t)
{
	while (g[t] != NULL)
	{
		r[i] = ft_strdup(g[t]);
		i++;
		t++;
	}
	return (i);
}

char	**cutnb(char **av, int ac, int d)
{
	char	**tmp;
	char	**tmp2;
	int		i;
	int		t;

	i = 0;
	tmp = ft_split(av[d], ' ');
	while (tmp[i] != NULL)
		i++;
	tmp2 = ft_calloc(sizeof(char *), (ac + i));
	i = 0;
	while (i < d)
	{
		tmp2[i] = ft_strdup(av[i]);
		i++;
	}
	t = i + 1;
	i = filllist(tmp2, tmp, i, 0);
	filllist(tmp2, av, i, t);
	freelist(av, tmp);
	return (tmp2);
}

int	multinm(char *a)
{
	int	i;

	i = 0;
	while (a[i] == ' ')
		i++;
	while (a[i] != ' ' && a[i] != '\0')
		i++;
	while (a[i] != '\0')
	{
		if (a[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**checkparsing(char **av, int *ac)
{
	int		i;
	int		z;

	i = 0;
	while (av[i] != NULL)
	{
		z = accalculate(av);
		if (multinm(av[i]) == 1)
		{
			av = cutnb(av, z, i);
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (av[i] != NULL)
		i++;
	*ac = i;
	return (av);
}
