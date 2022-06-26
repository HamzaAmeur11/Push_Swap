/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:25:48 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 14:24:22 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include "push_swap.h"
# include "get_next_line/get_next_line.h"

void	read_instructions(t_stack **s_a, t_stack **s_b, char *arg);
int		ft_strcmp(char *s1, char *s2);
void	fct(t_stack **s_a, t_stack **s_b);

#endif