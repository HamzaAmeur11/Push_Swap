/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:05:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/16 18:34:47 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_error(int i, char *str)
{
	if (str != NULL)
		free(str);
	if(i == 0)
		return (printf("daplicate number"), exit(1)); 
	else if (i == 1)
		return (printf("error f les argument"), exit(1));
	else if (i == 2)
		return (printf("max ou min int"), exit(1));
}

long int	ft_atoi(char *str)
{
	long int	resultat;
	long int	signe;
	int	i;

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
			ft_error(2, NULL);
	return (resultat * signe);
}

t_stack *initialization(t_stack *list, char *str)
{
	t_stack *p_new;

	p_new = ft_lstnew(ft_atoi(str));
	ft_lstadd_back(&list, p_new);
	return (list);
}

void check_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[0] == '-')
			i++;
		while (str[i] >= '0'  && str[i] <= '9')
			i++;
		if (str[i] != 0)
			ft_error(1, str);
	}
}

t_stack *ft_remplissage(char *str, t_stack *list)
{
	int	i;
	int	j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)malloc(20);
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
	free (s);
	return (list);
}
