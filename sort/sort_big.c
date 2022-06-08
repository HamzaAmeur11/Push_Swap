/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/08 22:02:50 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_stack **zero(t_stack **s_b)
{
	t_stack *zero;
	
	zero = (t_stack *)malloc(sizeof(t_stack));
	zero->index = 0;
	zero->next = NULL;
	zero->x = 0;
	*s_b = zero;
	return (s_b);
}

void	ft_fct(t_stack **s_a, t_stack **s_b)
{
	t_stack *first;
	t_stack *midle;
	t_stack *ptr = *s_a;
	int i = 0;
	int j = 0;
	
	s_b = zero(s_b);
	midle = *s_b;
	first = *s_b;
	while(ptr != NULL)
	{
		if(ptr->index % 2 == 0)
		{
			while (ptr->index < first->index)
			{
				rotate_b(s_b);
				first = *s_b;
				i++;
			}
			push_b(s_b, s_a);
			while (i-- >= 0)
				r_rotate_b(s_b);
			first = *s_b;
		}
	}
	
}