/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallcase2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:16:41 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 12:44:32 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mmtab(t_pile *p, t_pile *p2)
{
	if (p2->pl[0] == 1 && (p2->nbel == 2 && p2->pl[1] != 0))
	{
		while (p->pl[p->tail] != 0)
			rotate(p, "ra\n");
	}
	if (p2->pl[0] == 2 && (p2->nbel == 2 && p2->pl[1] != 1))
	{
		while (p->pl[p->tail] != 1)
			rotate(p, "ra\n");
	}
	if (p2->pl[0] == 2 && (p2->nbel == 2 && p2->pl[1] != 3))
	{
		while (p->pl[0] != 3)
			rotate(p, "ra\n");
	}
	if (p2->pl[0] == 3 && (p2->nbel == 2 && p2->pl[1] != 4))
	{
		while (p->pl[0] != 4)
			rotate(p, "ra\n");
	}
	if (p2->nbel == 2)
		push(p2, p, "pa\n");
}

void	mmtab2(t_pile *p, t_pile *p2)
{
	int	a;

	a = p2->pl[0];
	a++;
	if (p2->pl[0] == 4)
	{
		while (p->pl[0] != 0)
			rotate(p, "ra\n");
	}
	else
	{
		while (p->pl[0] != a)
			rotate(p, "ra\n");
	}
	push(p2, p, "pa\n");
}

void	cas5(t_pile *p, t_pile *p2)
{
	int	t;

	push(p, p2, "pb\n");
	push(p, p2, "pb\n");
	cas3(p);
	if (p2->pl[0] == 0 || p2->pl[0] == 4)
		push(p2, p, "pa\n");
	mmtab(p, p2);
	mmtab2(p, p2);
	t = 0;
	while (p->pl[t] != 0)
		t++;
	if (t < 2)
	{
		while (p->pl[0] != 0)
			rotate(p, "ra\n");
	}
	else
	{
		while (p->pl[0] != 0)
			rr1(p, "rra\n");
	}
}
