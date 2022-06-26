/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:53 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 02:00:22 by hameur           ###   ########.fr       */
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

void push_int(t_stack **s_a, t_stack **s_b, int push, int size)
{
	t_stack *first;
	int i = -1;
	
	first = *s_b;
	while (++i >= 0 && first->index != push)
		first = first->next;
	int j = 0;
	if (i <= size / 2)
	{
		while (j++ < i)
			rotate_b(s_b, 1);
		push_a(s_a, s_b, 1);
	}
	else if (i > size / 2)
	{
		while (first != NULL && j++ >= 0)
			first = first->next;
		i = j;
		while (j-- > 0)
			r_rotate_b(s_b, 1);
		push_a(s_a, s_b, 1);
	}
}

void remplisage_a(t_stack **s_a, t_stack **s_b, int size)
{
	int max = max_int(*s_b);
	

	while (max >= 0)
		push_int(s_a, s_b,max--, size--);
}

void check_correct(t_stack **stk)
{
	t_stack *temp;

	temp = *stk;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			break ;
		temp = temp->next;
	}
}

void rank_stacks(t_stack **stk, int size)
{
	t_stack	*rank;
	t_stack	*temp;
	int i = 0;
	
	rank = *stk;
	temp = rank->next;
	while (rank != NULL)
	{
		while (temp != rank && ++i > 0)
		{
			if (temp == NULL)
				temp = *stk;
			if (rank->x == temp->x && i != size)
				ft_error(NULL);
			if (rank->x < temp->x)
				temp = temp->next;
			else if (rank->x > temp->x && rank->index++ >= 0)
				temp = temp->next;
		}
		i = 0;
		if (rank->next == NULL)
			break ;
		rank = rank->next;
		temp = rank->next;
		if (temp == NULL)
			temp = *stk;
	}
	check_correct(stk);
}