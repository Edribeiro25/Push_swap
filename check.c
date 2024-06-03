/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:22:42 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 14:30:08 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exitr(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
	write(2, "Error\n", 6);
	exit(0);
}

void	min(char *c, char **av)
{
	if (c[0] > '-')
		exitr(av);
	if (c[1] > '2')
		exitr(av);
	if (c[2] > '1')
		exitr(av);
	if (c[3] > '4')
		exitr(av);
	if (c[4] > '7')
		exitr(av);
	if (c[5] > '4')
		exitr(av);
	if (c[6] > '8')
		exitr(av);
	if (c[7] > '3')
		exitr(av);
	if (c[8] > '6')
		exitr(av);
	if (c[9] > '4')
		exitr(av);
	if (c[10] > '8')
		exitr(av);
}

void	max(char *c, char **av)
{
	if (c[0] > '2')
		exitr(av);
	if (c[1] > '1')
		exitr(av);
	if (c[2] > '4')
		exitr(av);
	if (c[3] > '7')
		exitr(av);
	if (c[4] > '4')
		exitr(av);
	if (c[5] > '8')
		exitr(av);
	if (c[6] > '3')
		exitr(av);
	if (c[7] > '6')
		exitr(av);
	if (c[8] > '4')
		exitr(av);
	if (c[9] > '7')
		exitr(av);
}

void	charcheck(char *c, char **av)
{
	int	i;

	i = 0;
	if (c[0] == '-')
		i++;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			exitr(av);
		i++;
	}
}

int	checkmaxminchar(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_strlen(av[i]) > 11)
			exitr(av);
		if (ft_strlen(av[i]) == 10)
			max(av[i], av);
		if (ft_strlen(av[i]) == 11)
			min(av[i], av);
		charcheck(av[i], av);
		i++;
	}
}
