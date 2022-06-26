/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:10:43 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 01:53:36 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_b(t_stack **stack_b, int i)
{
	long int temp;

	temp = (*stack_b)->x;
	(*stack_b)->x = (*stack_b)->next->x;
	(*stack_b)->next->x = temp;
	if (i == 1)
		printf("sb\n");
}


void rotate_b(t_stack **s_b, int i)
{
	t_stack *ptr;
	
	if ((*s_b)->next == NULL)
		return ;
	ptr = *s_b;
	*s_b = (*s_b)->next;
	ptr->next = NULL;
	s_b = ft_lstadd_back(s_b, ptr);
	if (i == 1)
		printf("rb\n");
}

void r_rotate_b(t_stack **s_b, int i)
{
	t_stack *ptr;

	ptr = *s_b;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	ft_lstadd_front(s_b, ptr->next);
	ft_lstdelone(ptr);
	ptr->next = NULL;
	if (i == 1)
		printf("rrb\n");
}

t_stack *push_b(t_stack **s_b, t_stack **s_a, int i)
{
	t_stack *temp;

	if (!(*s_a))
	{
		printf("push_b :: stack_a empty");
		exit(1);
	}
	temp = (*s_a);
	(*s_a) = temp->next;
	temp->next = NULL;
	*s_b = ft_lstadd_front(s_b, temp);
	if (i == 1)
		printf("pb\n");
	return (*s_b);
}