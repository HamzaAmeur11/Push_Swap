/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:47:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/03 20:13:34 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(t_stack **s_a)
{
	int i = ft_lstsize(*s_a);

	if (i == 2)
	{
		if ((*s_a)->x > ((*s_a)->next->x))
			return (swap_a(s_a));
		else if ((*s_a)->x < ((*s_a)->next->x))
			return ;
		else
			return (printf("sort 2 :: duplicate number\n"), exit(1));
	
	}
	else
		return (printf("sort 2 :: many two argument in stack_a\n"), exit(1));
}

void sorte_three_II(t_stack **s_a)
{
	if ((*s_a)->x > (*s_a)->next->x)
	{
		if ((*s_a)->next->x > (*s_a)->next->next->x)
			return (swap_a(s_a), r_rotate_a(s_a));
		else if ((*s_a)->next->x < (*s_a)->next->next->x)
		{
			if ((*s_a)->x > (*s_a)->next->next->x)
				return (rotate_a(s_a));
			else if ((*s_a)->x < (*s_a)->next->next->x)
				return (swap_a(s_a));
			else if ((*s_a)->x == (*s_a)->next->next->x)
			ft_error(0, NULL);	
		}
		else if ((*s_a)->next->x == (*s_a)->next->next->x)
			ft_error(0, NULL);
	}
	else if ((*s_a)->x == (*s_a)->next->x)
		ft_error(0, NULL);
}


void sort_three(t_stack **s_a)
{
	check_stacks(*s_a, 3);
	if ((*s_a)->x < (*s_a)->next->x)
	{
		if ((*s_a)->next->x < (*s_a)->next->next->x)
			return ; // 1 2 3
		else if ((*s_a)->next->x > (*s_a)->next->next->x)
		{
			if((*s_a)->x > (*s_a)->next->next->x)
				return (r_rotate_a(s_a));
			else if((*s_a)->x < (*s_a)->next->next->x)
				return(swap_a(s_a), rotate_a(s_a));
			else if ((*s_a)->x == (*s_a)->next->next->x)
				ft_error(0, NULL);
		}
		else if ((*s_a)->next->x == (*s_a)->next->next->x)
			ft_error(0, NULL);
	}
	sorte_three_II(s_a);
}




void sort_four(t_stack **s_a, t_stack **s_b)
{
	int i;

	check_stacks(*s_a, 4);
	i = min_stack(*s_a);
	if (i == 2)
		swap_a(s_a);
	else if (i == 3)
	{
		rotate_a(s_a);
		swap_a(s_a);
	}
	else if (i == 4)
		r_rotate_a(s_a);
	push_b(s_b, s_a);
	sort_three(s_a);
	push_a(s_a, s_b);
}

void sort_five(t_stack **s_a, t_stack **s_b)
{
	int i;

	check_stacks(*s_a, 5);
	i = min_stack(*s_a);
	if (i == 2)
		swap_a(s_a);
	else if (i == 3)
	{
		rotate_a(s_a);
		rotate_a(s_a);
	}
	else if (i == 4)
	{
		r_rotate_a(s_a);
		r_rotate_a(s_a);
	}
	else if (i == 5)
		r_rotate_a(s_a);
	push_b(s_b, s_a);
	sort_four(s_a, s_b);
	push_a(s_a, s_b);
}