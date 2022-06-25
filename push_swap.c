/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 18:13:38 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void checker_sortin(t_stack **s_a)
{
	t_stack *temp;
	

	temp = *s_a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			break ;
			temp = temp->next;
	}
	if (temp->next == NULL)
		exit (0);
}


int main(int ac, char **av)
{
	t_stack *s_a;
	t_stack *s_b;
	t_stack **ref;
	int size;
	int i;

	if (ac <= 1)
		ft_error(NULL);
	i = 1;
	while (av[i])
		s_a = ft_remplissage(av[i++], s_a);
	size = ft_lstsize(s_a);
	if (size == 1)
		exit(0);
	if (size <= 5)
		ft_sort(&s_a, &s_b, size);
	rank_stacks(&s_a, size);
	checker_sortin(&s_a);
	ref = check_stack(&s_a, size);
	remplisage_b(&s_a, &s_b, ref, size);
	remplisage_a(&s_a, &s_b, size);
}
