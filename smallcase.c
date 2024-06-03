/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallcase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:16:32 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 16:14:21 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cas2(t_pile *p)
{
	if (p->pl[0] > p->pl[1])
		swap(p, "sa\n");
}

void	cas3(t_pile *p)
{
	if (p->pl[0] > p->pl[1] && p->pl[1] < p->pl[2] && p->pl[0] < p->pl[2])
		swap(p, "sa\n");
	if (p->pl[0] > p->pl[2] && p->pl[0] > p->pl[1] && p->pl[1] < p->pl[2])
		rotate(p, "ra\n");
	if (p->pl[0] < p->pl[1] && p->pl[0] > p->pl[2] && p->pl[1] > p->pl[2])
		rr1(p, "rra\n");
	if (p->pl[0] > p->pl[1] && p->pl[1] > p->pl[2])
	{
		swap(p, "sa\n");
		rr1(p, "rra\n");
	}
	if (p->pl[0] < p->pl[1] && p->pl[0] < p->pl[2] && p->pl[1] > p->pl[2])
	{
		swap(p, "sa\n");
		rotate(p, "ra\n");
	}
}

void	cas4(t_pile *p, t_pile *p2)
{
	push(p, p2, "pb\n");
	cas3(p);
	if (p2->pl[0] != 0)
	{
		while (p->pl[p->tail] != (p2->pl[0] - 1))
			rotate(p, "ra\n");
	}
	else
	{
		while (p->pl[p->tail] == 1)
			rotate(p, "ra\n");
	}
	push(p2, p, "pa\n");
	while (p->pl[0] != 0)
		rotate(p, "ra\n");
}

int	*acsup(int ac, char **av)
{
	t_pile	p;
	t_pile	d;

	p.nbel = ac;
	p.tail = ac - 1;
	p.pl = sortlargepile(av, ac);
	d.nbel = 0;
	d.tail = 0;
	d.pl = malloc(sizeof(int) * ac);
	if (!d.pl)
		return (NULL);
	if (ac == 2)
		cas2(&p);
	if (ac == 3)
		cas3(&p);
	if (ac == 4)
		cas4(&p, &d);
	if (ac == 5)
		cas5(&p, &d);
	free(d.pl);
	free(p.pl);
	return (NULL);
}
