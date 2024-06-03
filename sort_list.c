/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:46:03 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 16:16:57 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	pickchunk(int ac, char **av)
{
	t_chunk	c;
	int		i;

	if (ac < 10)
		i = 2;
	if (ac >= 10 && ac <= 100)
		i = 5;
	if (ac > 100)
		i = 11;
	c.max = (ac / i) - 1;
	c.min = 0;
	c.rest = ac % i;
	return (c);
}

void	changechunk(t_chunk *c)
{
	static int	tmp;

	if (c->min == 0)
		tmp = c->max - c->min + 1;
	c->min = c->min + tmp;
	c->max = c->max + tmp;
}

int	*initpile(t_pile *a, t_pile *b, char **av, int ac)
{
	a->nbel = ac;
	a->tail = ac - 1;
	a->pl = sortlargepile(av, ac);
	b->nbel = 0;
	b->tail = 0;
	b->pl = malloc(sizeof(int) * ac);
	if (!b->pl)
		return (NULL);
}

void	largecase(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	t_chunk	c;

	initpile(&a, &b, av, ac);
	c = pickchunk(ac, av);
	while (a.nbel != 0)
	{
		if (a.nbel > (c.max - c.min) + 1)
		{
			while (b.nbel < c.max + 1)
				fillb(&a, &b, &c);
			changechunk(&c);
		}
		else
		{
			while (a.nbel != 0)
				push(&a, &b, "pb\n");
		}
	}
	while (b.nbel != 0)
		filla(&a, &b);
	free(a.pl);
	free(b.pl);
}
