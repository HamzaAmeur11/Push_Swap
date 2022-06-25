/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/21 19:10:02 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack **check_stack(t_stack **s_a)
{
	int j = 0;
	int i = ft_lstsize(*s_a);
	t_stack *ptr = *s_a;
	t_stack **rtn;
	t_stack *temp2 = *s_a;
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

void del_pos(t_stack **ref, int index, int size)
{
	t_stack *current = *ref;
	t_stack *previous = *ref;

	if (index == (*ref)->index)
	{
		*ref = (*ref)->next;
		free(current);
		current = NULL;
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
		current = NULL;
	}
}

void fct(t_stack **s_a, t_stack **s_b, t_stack **ref, int size)
{
	int i = size;
	int j;
	t_stack *small;
	t_stack *big;
	t_stack *temp;

	while (*s_a != NULL && *ref != NULL)
	{
		small = *ref;
		big = *ref;
		j = -1;
		t_stack *tst = *ref;

		if (i == 1)
		{
			free(*ref);
			free(ref);
			*s_b = push_b(s_b, s_a);
			rotate_b(s_b);
			break;
		}
		while (++j <= i / 3 && big != NULL)
			big = big->next;
		j = -1;
		while (++j <= (i / 3) / 2 && small != NULL)
			small = small->next;
		if ((*s_a)->index > big->index && (*s_a)->index > small->index)
			rotate_a(s_a);
		else if ((*s_a)->index < big->index && (*s_a)->index < small->index)
		{
			del_pos(ref, (*s_a)->index, i);
			*s_b = push_b(s_b, s_a);
			i--;
			continue;
		}
		else if ((*s_a)->index <= big->index && (*s_a)->index >= small->index)
		{
			del_pos(ref, (*s_a)->index, i);
			*s_b = push_b(s_b, s_a);
			rotate_b(s_b);
			i--;
			continue;
		}
	}
}

int main(int ac, char **av)
{
	t_stack *s_a;
	t_stack *s_b;
	int i = 1;

	if (ac == 1)
		ft_error(1, NULL);
	while (av[i])
		s_a = ft_remplissage(av[i++], s_a);

	int size = ft_lstsize(s_a);

	rank_stacks(&s_a, size);
	t_stack **ref = check_stack(&s_a);
	fct(&s_a, &s_b, ref, size);
	remplisage_a(&s_a, &s_b, size);

	t_stack *tst = s_a;
	while (tst != NULL)
	{
		printf("s_b == %ld -> |%d|\n", tst->x, tst->index);
		tst = tst->next;
	}
	// chaech_repete()
	// divise_stack(&s_aa, &s_bb);
}
