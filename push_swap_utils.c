/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:53 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 03:12:32 by hameur           ###   ########.fr       */
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
int max_int(t_stack *stk)
{
	t_stack *temp = stk;
	int i = 0;
	while (temp != NULL)
	{
		if (i < temp->index)
			i  = temp->index;
		temp = temp->next;
	}
	return (i);
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
			rotate_b(s_b);
		push_a(s_a, s_b);
	}
	else if (i > size / 2)
	{
		while (first != NULL && j++ >= 0)
			first = first->next;
		i = j;
		while (j-- > 0)
			r_rotate_b(s_b);
		push_a(s_a, s_b);
	}
}
void remplisage_a(t_stack **s_a, t_stack **s_b, int size)
{
	int max = max_int(*s_b);
	

	while (max >= 0)
		push_int(s_a, s_b,max--, size);
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
				ft_error(1, NULL);
			if (rank->x < temp->x)
				temp = temp->next;
			else if (rank->x > temp->x)
			{
				rank->index++;	
				temp = temp->next;
			}

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


