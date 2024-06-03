/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:04 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 12:55:41 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *t, char *c)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = t->pl[i];
	while (i < t->tail)
	{
		t->pl[i] = t->pl[i + 1];
		i++;
	}
	t->pl[t->tail] = tmp;
	ft_putstr(c);
}

void	swap(t_pile *t, char *c)
{
	int	tmp;

	tmp = t->pl[0];
	t->pl[0] = t->pl[1];
	t->pl[1] = tmp;
	ft_putstr(c);
}

void	push(t_pile *t1, t_pile *t2, char *c)
{
	int	i;

	i = t2->tail + 1;
	while (i > 0)
	{
		t2->pl[i] = t2->pl[i - 1];
		i--;
	}
	t2->pl[0] = t1->pl[0];
	i = 0;
	while (i < t1->tail)
	{
		t1->pl[i] = t1->pl[i + 1];
		i++;
	}
	t1->pl[t1->tail] = 0;
	t1->tail--;
	t1->nbel--;
	if (t2->nbel > 0)
		t2->tail++;
	t2->nbel++;
	ft_putstr(c);
}

void	rr1(t_pile *t, char *c)
{
	int	tmp;
	int	i;

	i = t->tail;
	tmp = t->pl[t->tail];
	while (i > 0)
	{
		t->pl[i] = t->pl[i - 1];
		i--;
	}
	t->pl[0] = tmp;
	ft_putstr(c);
}
