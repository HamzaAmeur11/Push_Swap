/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:05:23 by hameur            #+#    #+#             */
/*   Updated: 2022/06/03 19:21:22 by hameur           ###   ########.fr       */
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

t_stack *fct(t_stack *list, char *str)
{
	t_stack *p_new;

	p_new = ft_lstnew(ft_atoi(str));
	ft_lstadd_back(&list, p_new);
	return (list);
}

t_stack *check_str(char *str, t_stack *list)
{
	int i;
	int j;
	char *s = (char *)malloc(20);

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		while (str[i] == ' ')
		{
			if (str[i + 1] == 0)
				return (list);
			i++;
		}
		if (str[i] == '-')
		{
			if (i == 0)
				s[j++] = str[i++];
			else if (i >= 1 && str[i + 1] >= '0' 
				&& str[i + 1] <= '9' && str[i - 1] == ' ')
				s[j++] = str[i++];
			else
				ft_error(1, s);	
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			s[j++] = str[i++];
			if (str[i] == ' ')
			{
				s[j] = 0;
				j = 0;
				i++;
				list = fct(list, s);
			}
			else if (str[i] == 0)
				return (s[j] = 0, fct(list, s));
		}
		else
			ft_error(1, s);
	}
	ft_error(1, s);
	return (NULL);
}	
