/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:58:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:46:39 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*reference(int size)
{
	int	*p;
	int	i;

	p = (int *)malloc((size + 1) * sizeof(int));
	i = -1;
	while (++i <= size)
		p[i] = i;
	p[i] = -1;
	return (p);
}

void	del_pos(int *ref, int index)
{
	int	i;
	int	j;

	i = 0;
	while (ref[i] != index)
		i++;
	j = i + 1;
	while (ref[i] != -1)
		ref[i++] = ref[j++];
}

void	ff(t_stack **s_a, t_stack **s_b, int *ref, int i)
{
	del_pos(ref, (*s_a)->index);
	*s_b = push_b(s_b, s_a, 1);
	if (i == 1)
		rotate_b(s_b, 1);
}

void	p_big_nd_small(int *big, int *small, int *ref, int i)
{
	int	j;

	*small = *ref;
	*big = *ref;
	j = -1;
	while (++j <= i / 5 && big != NULL)
		(*big) = ref[j];
	j = -1;
	while (++j <= (i / 5) / 2 && small != NULL)
		(*small) = ref[j];
}

void	remplisage_b(t_stack **s_a, t_stack **s_b, int size)
{
	int	*ref;
	int	small;
	int	big;

	ref = reference(size);
	while (*s_a != NULL && ref[size] != -1 && size > 1)
	{
		p_big_nd_small(&big, &small, ref, size);
		if (size <= 1)
			ft_error(NULL);
		if ((*s_a)->index > big && (*s_a)->index > small)
			rotate_a(s_a, 1);
		else
		{
			if ((*s_a)->index < big && (*s_a)->index < small)
				ff(s_a, s_b, ref, 0);
			else if ((*s_a)->index <= big && (*s_a)->index >= small)
				ff(s_a, s_b, ref, 1);
			size--;
		}
	}
	*s_b = push_b(s_b, s_a, 1);
	free(ref);
}
