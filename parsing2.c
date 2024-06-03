/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:01:08 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 15:43:02 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	spacecount(char *c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (c[i] != '\0')
	{
		if (c[i] == ' ')
			z++;
		i++;
	}
	z = i - z;
	return (z);
}

char	*removespace(char *c)
{
	int		i;
	int		z;
	char	*tmp;

	i = 0;
	z = spacecount(c);
	tmp = malloc(sizeof(char) * (z + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	tmp[z] = '\0';
	while (c[i] == ' ')
		i++;
	z = 0;
	while (c[i] != ' ' && c[i] != '\0')
	{
		tmp[z] = c[i];
		z++;
		i++;
	}
	free(c);
	return (tmp);
}

int	spacein(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	trimlist(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		if (spacein(list[i]) == 1)
			list[i] = removespace(list[i]);
		i++;
	}
}

void	checkdoublon(char **av, int ac)
{
	int	*p;
	int	i;
	int	z;

	i = 0;
	p = recuplist(ac, av);
	while (i < ac)
	{
		z = i + 1;
		while (z < ac)
		{
			if (p[i] == p[z])
			{
				free(p);
				exitr(av);
			}
			z++;
		}
		i++;
	}
	free(p);
}
