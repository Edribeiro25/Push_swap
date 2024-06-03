/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eribeiro <eribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:47:50 by eribeiro          #+#    #+#             */
/*   Updated: 2022/01/27 16:14:32 by eribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	int	*pl;
	int	nbel;
	int	tail;
}	t_pile;

typedef struct s_pole
{
	int	min;
	int	max;
}	t_pole;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	rest;
}	t_chunk;

void	*ft_calloc(size_t count, size_t size);
void	largecase(int ac, char **av);
void	ft_putstr(char *s);
void	exitr(char **av);
void	rotate(t_pile *t, char *c);
void	swap(t_pile *t, char *c);
void	push(t_pile *t1, t_pile *t2, char *c);
void	rr1(t_pile *t, char *c);
void	filla(t_pile *a, t_pile *b);
void	fillb(t_pile *a, t_pile *b, t_chunk *c);
void	cas3(t_pile *p);
void	cas5(t_pile *p, t_pile *p2);
void	checkdoublon(char **av, int ac);
void	trimlist(char **list);

char	**checkparsing(char **av, int *ac);
char	**ft_splitchar(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	**ac2(char **av, int *ac);

int		checkmaxminchar(char **av);
int		checklist(int c);
int		ft_strlen(const char *str);
int		*acsup(int ac, char **av);
int		*recuplist(int nbe, char **av);
int		*sortlargepile(char **av, int ac);
int		accalculate(char **av);

#endif
