/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/16 22:00:31 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *s_aa;
	t_stack *s_bb;
	int i = 1;
	
	if (ac == 1)
		ft_error(1, NULL);
	while (av[i])
		s_aa = ft_remplissage(av[i++], s_aa);
	rank_stacks(&s_aa);
	//valide 
	divise_stack(&s_aa, &s_bb);
	remplisage_a(&s_aa, &s_bb);
	s_bb = s_aa;
	while (s_bb != NULL)
	{
		printf("s_b : |%ld| -> %d\n", s_bb->x, s_bb->index);
		s_bb = s_bb->next;
	}
}