/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:53 by hameur            #+#    #+#             */
/*   Updated: 2022/06/03 18:56:32 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_stacks(t_stack *s, int error)
{
	int i;
	
	i = ft_lstsize(s);
	if (error == 3 && i != error)
		return (printf("sorte 3 :: many three argument in stack_a"), exit(1));
	else if(error == 4 && i != error)
		return (printf("sorte 4 :: many four argument in stack_a"), exit(1));
}

int min_stack(t_stack *s_a)
{
	t_stack *ptr;
	t_stack *temp;
	
	ptr = s_a;
	temp = s_a;
	while (ptr->next != NULL)
	{
		if (temp->x > ptr->next->x)
			temp = ptr->next;
		ptr = ptr->next;
	}
	return (ft_lstsize(s_a) - ft_lstsize(temp) + 1);	
}









void rank_stacks(t_stack **stk)
{
	t_stack *rank;
	t_stack	*temp;
	
	rank = *stk;
	temp = (*stk)->next;
	while (rank != NULL)
	{
		while (temp != rank)
		{
			if (rank->x < temp->x)
				temp = temp->next;
			else if (rank->x > temp->x)
			{
				rank->index++;	
				temp = temp->next;
			}
			if (temp == NULL)
				temp = *stk;
		}
		if (rank->next == NULL)
			break ;
		rank = rank->next;
		temp = rank->next;
		if (temp == NULL)
			temp = *stk;
	}
}
