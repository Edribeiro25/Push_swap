/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:31:11 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 16:08:07 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*recuplist(int nbe, char **av)
{
	int	i;
	int	*p;

	i = 0;
	p = malloc(sizeof(int) * nbe);
	if (!p)
		return (NULL);
	while (i < nbe)
	{
		p[i] = atoi(av[i]);
		i++;
	}
	return (p);
}

int	recupmax(int max, int nbe, int *pl, int *p)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	max = p[0];
	while (i < nbe)
	{
		if (p[i] > max)
		{
			max = p[i];
			pos = i;
		}
		i++;
	}
	pl[pos] = nbe - 1;
	return (max);
}

int	recupmin(int min, int nbe, int *pl, int *p)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	min = p[0];
	while (i < nbe)
	{
		if (p[i] < min)
		{
			min = p[i];
			pos = i;
		}
		i++;
	}
	pl[pos] = 0;
	return (min);
}

void	recuplist2(t_pole pole, int *pl, int *p, int ac)
{
	int	nbelem;
	int	tmp;
	int	pos;
	int	i;

	i = 0;
	nbelem = ac - 2;
	while (nbelem > 0)
	{
		i = 0;
		tmp = pole.max;
		pole.max = pole.min;
		while (i < ac)
		{
			if (p[i] > pole.min && p[i] > pole.max && p[i] < tmp)
			{
				pole.max = p[i];
				pos = i;
			}
			i++;
		}
		pl[pos] = nbelem--;
	}
}

int	*sortlargepile(char **av, int ac)
{
	int		*p;
	int		*pl;
	int		i;
	t_pole	pole;

	i = 0;
	p = recuplist(ac, av);
	pl = malloc(sizeof(int) * ac);
	if (!pl)
		return (NULL);
	pole.max = recupmax(0, ac, pl, p);
	pole.min = recupmin(0, ac, pl, p);
	recuplist2(pole, pl, p, ac);
	while (av[i] != NULL)
		free(av[i++]);
	free(av);
	free(p);
	return (pl);
}
