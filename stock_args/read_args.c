/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:05:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:01:54 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_int(t_stack *stk)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stk;
	while (temp != NULL)
	{
		if (i < temp->index)
			i = temp->index;
		temp = temp->next;
	}
	return (i);
}

long int	ft_atoi(char *str)
{
	long int	resultat;
	long int	signe;
	int			i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	if (resultat * signe > 2147483647
		|| resultat * signe < -2147483648)
		ft_error(NULL);
	return (resultat * signe);
}

t_stack	*initialization(t_stack *list, char *str)
{
	t_stack	*p_new;

	p_new = ft_lstnew(ft_atoi(str));
	ft_lstadd_back(&list, p_new);
	return (list);
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[0] == '-')
			i++;
		if (is_digit(str[i]) == 0)
			ft_error(str);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != 0)
			ft_error(str);
	}
}

t_stack	*ft_remplissage(char *str, t_stack *list)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)malloc(20);
	if (str[0] == 0)
		ft_error(s);
	while (str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 0)
			break ;
		while (str[i] && str[i] != ' ')
			s[j++] = str[i++];
		s[j] = '\0';
		check_str(s);
		list = initialization(list, s);
		j = 0;
	}
	return (free (s), list);
}
