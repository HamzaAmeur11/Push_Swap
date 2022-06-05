/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/04 16:13:21 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *s_aa;
	t_stack *s_bb;
	
	if (ac == 1)
		ft_error(1, NULL);
	s_aa = NULL;
	s_aa = check_str(av[1], s_aa);
	rank_stacks(&s_aa);
	t_stack *temp = s_aa;
	while(temp != NULL)
	{
		printf("|%ld| == %d\n |\n",temp->x, temp->index);
		temp = temp->next;
	}
	printf("\n\n");
	ft_fct(&s_aa, &s_bb);
	while(s_bb != NULL)
	{
		printf("|%ld| == %d\n |\n",s_bb->x, s_bb->index);
		s_bb = s_bb->next;
	}
}