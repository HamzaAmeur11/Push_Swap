/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/21 19:10:02 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack **check_stack(t_stack **s_a)
{
	int j = 0;
	int i = ft_lstsize(*s_a);
	t_stack *ptr = *s_a;
	t_stack **rtn;
	t_stack *temp = (t_stack *)malloc(sizeof(t_stack));

	*rtn = temp;
	t_stack *temp2 = *s_a;
	while (temp2 != NULL)
	{
		printf("tst stack : %ld => |%d|\n", temp2->x, temp2->index);
		temp2 = temp2->next;
	}
	while (ptr != NULL)
	{
		if (ptr->index == j)
		{
			temp->next = (t_stack *)malloc(sizeof(t_stack));
			temp->index = j++;
			temp->x = ptr->x;
			if (j == i)
				return (temp->next = NULL , rtn);
			temp = temp->next;
			ptr = *s_a;
		}
		else
			ptr = ptr->next;
	}
	return (rtn);
}


int main(int ac, char **av)
{
	t_stack *s_aa;
	t_stack **s_bb;
	int i = 1;
	
	if (ac == 1)
		ft_error(1, NULL);
	while (av[i])
		s_aa = ft_remplissage(av[i++], s_aa);
	
	rank_stacks(&s_aa);
	t_stack *s_b = s_aa;
	while (s_b != NULL)
	{
	 	printf("s_b : |%ld| -> %d\n", s_b->x, s_b->index);
	 	s_b = s_b->next;
	}
	s_bb = check_stack(&s_aa);
	//chaech_repete()
	//divise_stack(&s_aa, &s_bb);
	//remplisage_a(&s_aa, &s_bb);
}