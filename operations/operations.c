/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:12:58 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 02:06:25 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void s_swap(t_stack **s_a, t_stack **s_b)
{
	swap_a(s_a, 0);
	swap_b(s_b, 0);
}

void r_rotate(t_stack **s_a, t_stack **s_b)
{
	rotate_a(s_a, 0);
	rotate_b(s_b, 0);
}

void rr_rotate(t_stack **s_a, t_stack **s_b)
{
	r_rotate_a(s_a, 0);
	r_rotate_b(s_b, 0);
}