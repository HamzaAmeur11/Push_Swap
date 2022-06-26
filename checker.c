/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:25:51 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 14:23:18 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fct(t_stack **s_a, t_stack **s_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		read_instructions(s_a, s_b, str);
		str = get_next_line(0);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

void	read_instructions(t_stack **s_a, t_stack **s_b, char *arg)
{
	if (ft_strcmp(arg, (char *)"sa\n") == 0)
		swap_a(s_a, 0);
	else if (ft_strcmp(arg, (char *)"sb\n") == 0)
		swap_b(s_b, 0);
	else if (ft_strcmp(arg, (char *)"ss\n") == 0)
		s_swap(s_a, s_b);
	else if (ft_strcmp(arg, (char *)"pb\n") == 0)
		push_b(s_b, s_a, 0);
	else if (ft_strcmp(arg, (char *)"pa\n") == 0)
		push_a(s_a, s_b, 0);
	else if (ft_strcmp(arg, (char *)"ra\n") == 0)
		rotate_a(s_a, 0);
	else if (ft_strcmp(arg, (char *)"rb\n") == 0)
		rotate_b(s_b, 0);
	else if (ft_strcmp(arg, (char *)"rr\n") == 0)
		r_rotate(s_a, s_b);
	else if (ft_strcmp(arg, (char *)"rra\n") == 0)
		r_rotate_a(s_a, 0);
	else if (ft_strcmp(arg, (char *)"rrb\n") == 0)
		r_rotate_b(s_b, 0);
	else if (ft_strcmp(arg, (char *)"rrr\n") == 0)
		rr_rotate(s_a, s_b);
	else
		ft_error(NULL);
}

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
	checker_sortin(&s_a);
	fct(&s_a, &s_b);
	i = checker_sortin(&s_a);
	if (i == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
