/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/06 02:33:36 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void foct(t_stack **s_a, t_stack **s_b)
{
	zero(s_b);
	t_stack *tst = *s_b;
	printf("tst s_b == %ld\ntst tst == %ld\n",(**s_b).x ,tst->x);
	push_b(s_b, s_a);
	// (*s_b) = (*s_b)->next;
	printf("tst tst == %ld\n", tst->x);
	printf("tst s_b == %ld\n", (**s_b).x);
	
}


int main(int ac, char **av)
{
	t_stack *s_aa;
	t_stack *s_bb;
	
	if (ac == 1)
		ft_error(1, NULL);
	(void)av;
	s_aa = NULL;
	s_aa = check_str(av[1], s_aa);
	foct(&s_aa, &s_bb);
	// rank_stacks(&s_aa);
	// t_stack *temp = s_aa;
	// while(temp != NULL)
	// {
	// 	printf("|%ld| == %d\n |\n",temp->x, temp->index);
	// 	temp = temp->next;
	// }
	// printf("\n\n");
	// ft_fct(&s_aa, &s_bb);
	// while(s_bb != NULL)
	// {
	// 	printf("|%ld| == %d\n |\n",s_bb->x, s_bb->index);
	// 	s_bb = s_bb->next;
	// }
}