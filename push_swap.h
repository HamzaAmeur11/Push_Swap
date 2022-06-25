/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:54:02 by hameur            #+#    #+#             */
/*   Updated: 2022/06/25 18:23:14 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUCH_SWAP_H

#define PUCH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  t_stack
{
	long int		x;
	int				index;
	struct t_stack 	*next;
}	t_stack;


//____________linked list fonction____________//

t_stack	*ft_lstnew(int	content);
t_stack *ft_lstlast(t_stack *lst);
t_stack *ft_lstdelfirst(t_stack *list);
t_stack *ft_lstadd_front(t_stack **lst, t_stack *t_new);
t_stack **ft_lstadd_back(t_stack **lst, t_stack *t_new);
int		ft_lstsize(t_stack *lst);
void ft_lstdelone(t_stack *lst);
// ^^ passer list li 9bl mn li ba4i tms7
void ft_lstclear(t_stack **lst);


//ljshv
long int	ft_atoi(char *str);
void ft_error(char *str);
t_stack *initialization(t_stack *list, char *str);
void	check_str(char *str);
t_stack *ft_remplissage(char *str, t_stack *list);
void check_correct(t_stack **stk);
void	clr_lst(t_stack **root, t_stack *node);
int	is_digit(char str);
void checker_sortin(t_stack **s_a);

//_______________stacks_operations_______________//
t_stack *push_b(t_stack **s_b, t_stack **s_a);
t_stack *push_a(t_stack **s_a, t_stack **s_b);
void rotate_a(t_stack **s_a);
void rotate_b(t_stack **s_b);
void swap_a(t_stack **stack_a);
void swap_b(t_stack **stack_b);
void r_rotate_a(t_stack **s_a);
void r_rotate_b(t_stack **s_b);
void s_swap(t_stack **s_a, t_stack **s_b);
void r_rotate(t_stack **s_a, t_stack **s_b);
void rr_rotate(t_stack **s_a, t_stack **s_b);


//_______________sorting_2_3_4_5_______________//
void check_stacks(t_stack *s, int error);
int min_stack(t_stack *s_a);
void sort_two(t_stack **s_a);
void sort_three(t_stack **s_a);
void sort_four(t_stack **s_a, t_stack **s_b);
void sort_five(t_stack **s_a, t_stack **s_b);
void ft_sort(t_stack **s_a, t_stack **s_b, int i);

//sort big
t_stack **check_stack(t_stack **s_a, int size);
void del_pos(t_stack **ref, int index);
void remplisage_b(t_stack **s_a, t_stack **s_b, t_stack **ref, int size);
void rank_stacks(t_stack **stk, int size);
void remplisage_a(t_stack **s_a, t_stack **s_b, int size);
void push_int(t_stack **s_a, t_stack **s_b, int push, int size);
void remplisage_b_2(t_stack **s_a, t_stack **s_b, t_stack **ref,t_stack *big, t_stack *small, int size);
int max_int(t_stack *stk);

#endif