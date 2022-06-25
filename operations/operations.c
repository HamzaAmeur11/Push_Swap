/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:12:58 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 19:12:49 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void s_swap(t_stack **s_a, t_stack **s_b)
{
	swap_a(s_a);
	swap_b(s_b);
}

void r_rotate(t_stack **s_a, t_stack **s_b)
{
	rotate_a(s_a);
	rotate_b(s_b);
}

void rr_rotate(t_stack **s_a, t_stack **s_b)
{
	r_rotate_a(s_a);
	r_rotate_b(s_b);
}