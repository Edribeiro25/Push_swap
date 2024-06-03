/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filla.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:35:42 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 11:53:54 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mouvtop2(t_pile *a, int d)
{
	int	i;

	i = 0;
	while (i <= a->tail)
	{
		if (a->pl[i] == d)
			return (i);
		i++;
	}
	return (0);
}

int	mouvtail2(t_pile *a, int d)
{
	int	i;
	int	ct;

	i = a->tail;
	ct = 1;
	while (i != 0)
	{
		if (a->pl[i] == d)
			return (ct);
		ct++;
		i--;
	}
	return (0);
}

void	filla(t_pile *a, t_pile *b)
{
	int	mouv;
	int	mouv2;

	mouv = mouvtop2(b, b->nbel - 1);
	mouv2 = mouvtail2(b, b->nbel - 1);
	if (mouv == 1)
	{
		swap(b, "sb\n");
		mouv--;
	}
	if (mouv <= mouv2 && mouv != 0)
	{
		while (mouv-- > 0)
			rotate(b, "rb\n");
	}
	if (mouv2 < mouv && mouv != 0)
	{
		while (mouv2-- > 0)
			rr1(b, "rrb\n");
	}
	push(b, a, "pa\n");
}
