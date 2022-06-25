/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 18:20:45 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack **check_stack(t_stack **s_a, int size)
{
	int j = 0;
	int i = size;
	t_stack *ptr = *s_a;
	t_stack **rtn;
	t_stack *temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	rtn = (t_stack **)malloc(sizeof(t_stack *));
	*rtn = temp;

	while (ptr != NULL)
	{
		if (ptr->index == j)
		{
			temp->next = (t_stack *)malloc(sizeof(t_stack));
			temp->index = j++;
			temp->x = ptr->x;
			if (j == i)
				return (temp->next = NULL, rtn);
			temp = temp->next;
			ptr = *s_a;
		}
		else
			ptr = ptr->next;
	}
	return (rtn);
}

void del_pos(t_stack **ref, int index)
{
	t_stack *current = *ref;
	t_stack *previous = *ref;
	
	if (index == (*ref)->index)
	{
		*ref = (*ref)->next;
		free(current);
	}
	else
	{
		while (current->index != index)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		free(current);
	}
}


void remplisage_b_2(t_stack **s_a, t_stack **s_b, t_stack **ref,t_stack *big, t_stack *small, int size)
{
	if (size <= 1)
		ft_error(NULL);
	if ((*s_a)->index < big->index && (*s_a)->index < small->index)
	{
		del_pos(ref, (*s_a)->index);
		*s_b = push_b(s_b, s_a);
	}
	else if ((*s_a)->index <= big->index && (*s_a)->index >= small->index)
	{
		del_pos(ref, (*s_a)->index);
		*s_b = push_b(s_b, s_a);
		rotate_b(s_b);
	}
}

void remplisage_b(t_stack **s_a, t_stack **s_b, t_stack **ref, int size)
{
	int i;
	int j;
	t_stack *small;
	t_stack *big;

	i = size;
	while (*s_a != NULL && *ref != NULL && i > 1)
	{
		small = *ref;
		big = *ref;
		j = -1;
		while (++j <= i / 5 && big != NULL)
			big = big->next;
		j = -1;
		while (++j <= (i / 5) / 2 && small != NULL)
			small = small->next;
		if ((*s_a)->index > big->index && (*s_a)->index > small->index)
			rotate_a(s_a);
		else
			remplisage_b_2(s_a, s_b, ref, big, small, i--);
	}
	*s_b = push_b(s_b, s_a);
}



