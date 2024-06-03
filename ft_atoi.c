/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:39:33 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 12:57:09 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int j)
{
	if (j < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned int	r;

	r = 0;
	i = 0;
	j = 1;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i++] - '0');
		if (r > 2147483648)
			return (check(j));
	}
	return (j * r);
}
