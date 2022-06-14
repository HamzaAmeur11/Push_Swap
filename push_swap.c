/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/14 04:51:17 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void remplisage_a(t_stack **s_a, t_stack **s_b)
{
	t_stack *last;

	if (*s_b == NULL)
		exit(1);
	last = ft_lstlast(*s_b);
	while (*s_b != NULL)
	{
		if (last->index > (*s_b)->index)
			r_rotate_b(s_b);
		push_a(s_a, s_b);
		last = ft_lstlast(*s_b);
	}
}

int main(int ac, char **av)
{
	t_stack *s_aa;
	t_stack *s_bb;
	int i = 1;
	
	if (ac == 1)
		ft_error(1, NULL);
	while (av[i])
		s_aa = check_str(av[i++], s_aa);
	rank_stacks(&s_aa);
	divise_stack(&s_aa, &s_bb);
	remplisage_a(&s_aa, &s_bb);
	t_stack *tst = s_aa;
	while (tst != NULL)
	{
		printf ("| %ld | == %d\n",tst->x, tst->index);
		tst = tst->next;
	}
}