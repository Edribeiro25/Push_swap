/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:43 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 12:57:27 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mouvtop(t_pile *a, t_chunk *c)
{
	int	i;

	i = 0;
	while (i <= a->tail)
	{
		if (a->pl[i] <= c->max && a->pl[i] >= c->min)
			return (i);
		i++;
	}
	return (0);
}

int	mouvtail(t_pile *a, t_chunk *c)
{
	int	i;
	int	ct;

	i = a->tail;
	ct = 1;
	while (i != 0)
	{
		if (a->pl[i] <= c->max && a->pl[i] >= c->min)
			return (ct);
		ct++;
		i--;
	}
	return (0);
}

void	fillb(t_pile *a, t_pile *b, t_chunk *c)
{
	int	mouv;
	int	mouv2;

	mouv = mouvtop(a, c);
	mouv2 = mouvtail(a, c);
	if (mouv == 1)
	{
		swap(a, "sa\n");
		mouv--;
	}
	if (mouv <= mouv2 && mouv != 0)
	{
		while (mouv-- > 0)
			rotate(a, "ra\n");
	}
	if (mouv2 < mouv && mouv != 0)
	{
		while (mouv2-- > 0)
			rr1(a, "rra\n");
	}
	push(a, b, "pb\n");
}
