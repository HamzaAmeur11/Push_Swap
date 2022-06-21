/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/21 02:42:47 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_find(t_stack **s_b, t_stack **s_a, int size, int index)
{
	t_stack *first;
	t_stack *midle;
	t_stack *temp;
	int i = 1;
	int j = 0;

	first = *s_a;
	midle = *s_a;
	while (i++ < (size / 2) && midle != NULL)
		midle = midle->next;
	i = 0;
	while (first->index != index && midle->index != index 
		&& midle != NULL)
	{
		first = first->next;
		midle = midle->next;
		i++;
	}
	temp = midle;
	while (midle->index == index && temp!= NULL && j++ >= 0)
		temp = temp->next;
	while (first->index == index && i-- > 0)
		rotate_a(s_a);
	while (midle->index == index && j-- > 0)
		r_rotate_a(s_a);
	push_b(s_b, s_a);
	first = *s_a;midle = *s_b;
}

t_stack **zero(t_stack **s_b, t_stack **s_a)
{
	int i;

	i = 0;
	i = ft_lstsize(*s_a);
	if (i == 1)
		exit (0);
	if (i <= 5)
		ft_sort(s_a, s_b, i);
	ft_find(s_b, s_a, i, 0);
	ft_find(s_b, s_a, i - 1, 1);
	rotate_b(s_b);
	return (s_b);
}

void push_up(t_stack **s_b, t_stack **s_a, t_stack **first)
{
	t_stack *temp;
	int i;
	
	i = 0;
	temp = *s_b;
	while ((*s_a)->index < (*s_b)->index && (*s_b)->index != 0)
	{
		rotate_b(s_b);
		i++;
	}
	push_b(s_b, s_a);
	while (i-- > 0)
		r_rotate_b(s_b);
	first = s_b;
	}


void push_down(t_stack **s_b, t_stack **s_a, t_stack **midle)
{
	int i;
	int j;
	t_stack *temp;

	i = 0;
	j = 0;
	temp = *midle;
	while (temp != NULL)
	{
		if ((*s_a)->index < temp->index)
			i++;
			temp = temp->next;
	}
	j = i + 1;
	while (i-- > 0)
		r_rotate_b(s_b);
	*s_b = push_b(s_b, s_a);
	while (j-- > 0)
		rotate_b(s_b);
}


void	divise_stack(t_stack **s_a, t_stack **s_b)
{
	t_stack *first;
	t_stack *midle;
	
	s_b = zero(s_b, s_a);
	first = *s_b;
	midle = (*s_b)->next;
	while (*s_a != NULL)
	{
		if ((*s_a)->index % 2 == 0)
			push_up(s_b, s_a, &first);
		else if ((*s_a)->index % 2 == 1)
			push_down(s_b, s_a, &midle);
	}
}





void check_stack(t_stack **s_a)
{
	t_stack *temp;
	t_stack *ptr;
	int i = ft_lstsize(*s_a);

	ptr = *s_a;
	while (i-- > 0)
	{
		
	}

	
}