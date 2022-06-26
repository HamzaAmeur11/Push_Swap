/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:46:17 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:09:00 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack_a, int i)
{
	long int	temp;

	temp = (*stack_a)->x;
	(*stack_a)->x = (*stack_a)->next->x;
	(*stack_a)->next->x = temp;
	if (i == 1)
		printf("sa\n");
}

void	rotate_a(t_stack **s_a, int i)
{
	t_stack	*ptr;

	if ((*s_a)->next == NULL)
		return ;
	ptr = *s_a;
	*s_a = (*s_a)->next;
	ptr->next = NULL;
	ft_lstadd_back(s_a, ptr);
	if (i == 1)
		printf("ra\n");
}

void	r_rotate_a(t_stack **s_a, int i)
{
	t_stack	*ptr;

	ptr = *s_a;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	ft_lstadd_front(s_a, ptr->next);
	ft_lstdelone(ptr);
	ptr->next = NULL;
	if (i == 1)
		printf("rra\n");
}

t_stack	*push_a(t_stack **s_a, t_stack **s_b, int i)
{
	t_stack	*temp;

	if (!(*s_b))
	{
		printf("push_a :: stack_b empty");
		exit(1);
	}
	temp = (*s_b);
	(*s_b) = (*s_b)->next;
	temp->next = NULL;
	*s_a = ft_lstadd_front(s_a, temp);
	if (i == 1)
		printf("pa\n");
	return (*s_a);
}
