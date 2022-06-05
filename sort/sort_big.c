/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/04 16:15:01 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fct(t_stack **s_a, t_stack **s_b)
{
	t_stack *p = *s_a;
	int i = 1;
	int j = 15;

	if (ft_lstsize(*s_a) > 250)
		j = 25;

	while (p != NULL && *s_a != NULL)
	{
		if (p->index < i)
		{
			push_b(s_b, s_a);
			rotate_b(s_b);
			i++;
		}
		else if (p->index < i + j)
		{
			push_b(s_b, s_a);
			i++;
		}
		else
			rotate_a(s_a);
		if (ft_lstsize(*s_b) > 1)
		{
			if ((*s_b)->index < (*s_b)->next->index)
				swap_b(s_b);
		}
	}
	rank_stacks(s_b);
}