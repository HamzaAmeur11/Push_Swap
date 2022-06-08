/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:46:17 by hameur            #+#    #+#             */
/*   Updated: 2022/06/06 02:29:40 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_a(t_stack **stack_a)
{
	long int temp;

	temp = (*stack_a)->x;
	(*stack_a)->x = (*stack_a)->next->x;
	(*stack_a)->next->x = temp;
}

void rotate_a(t_stack **s_a)
{
	t_stack *ptr;
	
	ptr = *s_a;
	*s_a = (*s_a)->next;
	ptr->next = NULL;
	ft_lstadd_back(s_a, ptr);
}

void r_rotate_a(t_stack **s_a)
{
	t_stack *ptr;
	t_stack *t;

	ptr = *s_a;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	t = ptr->next;
	ptr->next = NULL;
	ft_lstadd_front(s_a, t);
}

t_stack *push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack *temp;

	if (!(*s_b))
	{
		printf("push_a :: stack_b empty");
		exit(1);
	}
	temp = (t_stack *)malloc(sizeof(t_stack));
	temp->x = (*s_b)->x;
	temp->index = (*s_b)->index;
	temp->next = NULL;
	*s_a = ft_lstadd_front(s_a, temp);
	*s_b = ft_lstdelfirst(*s_b);
	return (*s_a);
}