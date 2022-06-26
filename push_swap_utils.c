/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:53 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:40:37 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_int(t_stack **s_a, t_stack **s_b, int push, int size)
{
	t_stack	*first;
	int		i;
	int		j;

	i = -1;
	j = 0;
	first = *s_b;
	while (++i >= 0 && first->index != push)
		first = first->next;
	if (i <= size / 2)
	{
		while (j++ < i)
			rotate_b(s_b, 1);
	}
	else if (i > size / 2)
	{
		while (first != NULL && j++ >= 0)
			first = first->next;
		i = j;
		while (j-- > 0)
			r_rotate_b(s_b, 1);
	}
	push_a(s_a, s_b, 1);
}

void	remplisage_a(t_stack **s_a, t_stack **s_b, int size)
{
	int	max;

	max = max_int(*s_b);
	while (max >= 0)
		push_int(s_a, s_b, max--, size--);
}

void	check_correct(t_stack **stk)
{
	t_stack	*temp;

	temp = *stk;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			break ;
		temp = temp->next;
	}
}

void	rank_stacks_util(t_stack **stk, t_stack **temp,
		t_stack **rank, int size)
{
	int	i;

	i = 0;
	while (*temp != *rank && ++i > 0)
	{
		if (*temp == NULL)
			*temp = *stk;
		if ((*rank)->x == (*temp)->x && i != size)
			ft_error(NULL);
		if ((*rank)->x < (*temp)->x)
			*temp = (*temp)->next;
		else if ((*rank)->x > (*temp)->x && (*rank)->index++ >= 0)
			*temp = (*temp)->next;
	}
}

void	rank_stacks(t_stack **stk, int size)
{
	t_stack	*rank;
	t_stack	*temp;

	rank = *stk;
	temp = rank->next;
	while (rank != NULL)
	{
		rank_stacks_util(stk, &temp, &rank, size);
		if (rank->next == NULL)
			break ;
		rank = rank->next;
		temp = rank->next;
		if (temp == NULL)
			temp = *stk;
	}
	check_correct(stk);
}
