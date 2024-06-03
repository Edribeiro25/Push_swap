/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:43:22 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 16:37:36 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ac2(char **av, int *d)
{
	int	ac;
	int	t;

	t = 0;
	ac = 0;
	while (av[1][ac] != '\0')
	{
		if (av[1][ac] != ' ')
			t++;
		ac++;
	}
	if (t == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	av = ft_split(av[1], ' ');
	ac = 0;
	while (av[ac] != 0)
		ac++;
	*d = ac;
	return (av);
}

char	**ac3(char **av, int *l)
{
	int		c;
	int		d;
	char	**ls;

	c = 1;
	while (av[c] != NULL)
		c++;
	ls = ft_calloc(sizeof(char *), (c + 1));
	c = 1;
	d = 0;
	while (av[c] != NULL)
		ls[d++] = ft_strdup(av[c++]);
	*l = d;
	return (ls);
}

void	checkdsorted(char **list, int nbe)
{
	int	*p;
	int	i;
	int	z;

	i = 1;
	z = 1;
	p = recuplist(nbe, list);
	while (i < nbe)
	{
		if (p[i] < p[i - 1])
			z = 0;
		i++;
	}
	free(p);
	if (z == 1)
	{
		i = 0;
		while (list[i] != NULL)
		{
			free(list[i]);
			i++;
		}
		free(list);
		exit(0);
	}
}

void	checkempty(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		if (list[i][0] == '\0')
			exitr(list);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		nbe;
	char	**list;

	nbe = ac;
	if (ac == 1)
		return (0);
	if (ac == 2)
		list = ac2(av, &nbe);
	else
		list = ac3(av, &nbe);
	checkempty(list);
	list = checkparsing(list, &nbe);
	trimlist(list);
	checkmaxminchar(list);
	checkdoublon(list, nbe);
	checkdsorted(list, nbe);
	if (nbe >= 2 && nbe < 6)
		acsup(nbe, list);
	if (nbe > 5)
		largecase(nbe, list);
	return (0);
}
