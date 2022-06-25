/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:43:47 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 18:22:31 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

void ft_error(char *str)
{
	if (str != NULL)
		free(str);
	write(2, "Error\n", 6);
	exit(1);
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