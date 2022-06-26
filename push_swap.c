/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:07:12 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:47:51 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		size;
	int		i;

	if (ac <= 1)
		ft_error(NULL);
	i = 1;
	while (av[i])
		s_a = ft_remplissage(av[i++], s_a);
	size = ft_lstsize(s_a);
	if (size == 1)
		exit(0);
	rank_stacks(&s_a, size);
	if (size <= 5)
		ft_sort(&s_a, &s_b, size);
	if (checker_sortin(&s_a) == 0)
		exit (0);
	remplisage_b(&s_a, &s_b, size);
	remplisage_a(&s_a, &s_b, size);
	clr_lst(&s_a, s_a);
}
