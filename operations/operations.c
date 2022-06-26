/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:12:58 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:41:01 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s_swap(t_stack **s_a, t_stack **s_b)
{
	swap_a(s_a, 0);
	swap_b(s_b, 0);
}

void	r_rotate(t_stack **s_a, t_stack **s_b)
{
	rotate_a(s_a, 0);
	rotate_b(s_b, 0);
}

void	rr_rotate(t_stack **s_a, t_stack **s_b)
{
	r_rotate_a(s_a, 0);
	r_rotate_b(s_b, 0);
}

int	min_stack(t_stack *s_a)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = s_a;
	while (ptr->index != 0)
		i++;
	return (i);
}

void	check_stack_util(t_stack **temp, long int x, int *j)
{
	(*temp)->next = (t_stack *)malloc(sizeof(t_stack));
	(*temp)->index = (*j)++;
	(*temp)->x = x;
}
