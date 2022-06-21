/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:53 by hameur            #+#    #+#             */
/*   Updated: 2022/06/20 13:45:51 by hameur           ###   ########.fr       */
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

void remplisage_a(t_stack **s_a, t_stack **s_b)
{
	t_stack *last;

	if (*s_b == NULL)
		exit(1);
	last = ft_lstlast(*s_b);
	while (*s_b != NULL)
	{
		if (last->index > (*s_b)->index)
			r_rotate_b(s_b);
		push_a(s_a, s_b);
		last = ft_lstlast(*s_b);
	}
}

void ft_sort(t_stack **s_a, t_stack **s_b, int i)
{
	if (i == 2)
		sort_two(s_a);
	else if (i == 3)
		sort_three(s_a);
	else if (i == 4)
		sort_four(s_a, s_b);
	else if (i == 5)
		sort_five(s_a, s_b);
	exit(0);
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


void rank_stacks(t_stack **stk)
{
	t_stack	*rank;
	t_stack	*temp;
	
	rank = *stk;
	temp = rank->next;
	while (rank != NULL)
	{
		while (temp != rank)
		{
			if (temp == NULL)
				temp = *stk;
			if (rank->x < temp->x)
				temp = temp->next;
			else if (rank->x > temp->x)
			{
				rank->index++;	
				temp = temp->next;
			}
		}
		if (rank->next == NULL)
			break ;
		rank = rank->next;
		temp = rank->next;
		if (temp == NULL)
			temp = *stk;
	}
	check_correct(stk);
}


