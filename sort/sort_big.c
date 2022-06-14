/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/14 04:52:50 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_stack **zero(t_stack **s_b)
{
	t_stack *ptr;
	
	ptr = (t_stack *)malloc(sizeof(t_stack));
	ptr = ft_lstnew(0);
	ptr->index = 0;
	ft_lstadd_back(&ptr, ft_lstnew(1));
	ptr->next->index = 1;
	ptr->next->next = NULL;
	*s_b = ptr;
	return (s_b);
}

void push_up(t_stack **s_b, t_stack **s_a, t_stack **first)
{
	t_stack *temp;
	int i;
	
			i = 0;
			temp = *s_b;
			if ((*s_a)->index == 0)
			{
				(*first)->x = (*s_a)->x;
				ft_lstdelfirst(*s_a);
			}
			while ((*s_a)->index < (*s_b)->index && (*s_b)->index != 1)
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
			if ((*s_a)->index == 1)
			{
				(*midle)->x = (*s_a)->x;
				*s_a = ft_lstdelfirst(*s_a);
			}
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


void	ft_fct(t_stack **s_a, t_stack **s_b)
{
	t_stack *first;
	t_stack *midle;
	
	s_b = zero(s_b);
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