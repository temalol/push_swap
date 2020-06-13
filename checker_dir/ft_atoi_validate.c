/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:19:46 by nmustach          #+#    #+#             */
/*   Updated: 2020/03/25 18:41:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	move_and_update_pointer(char *str, char **strnext, int is_num_ret)
{
	if (str[is_num_ret] == ' ')
	{
		if (!str[is_num_ret + 1])
			return (0);
		str[is_num_ret] = 0;
		*strnext = &str[is_num_ret + 1];
	}
	else
		*strnext = &str[is_num_ret];
	return (1);
}

int	parse_and_push(char *str, t_node **stack_a)
{
	int		is_num_ret;
	long	num;
	char	*strnext;

	while (*str)
	{
		if ((is_num_ret = is_number(str)) > 0)
		{
			if (str[is_num_ret] != ' ' && str[is_num_ret] != '\0')
				return (0);
			if (!move_and_update_pointer(str, &strnext, is_num_ret))
				return (0);
			if (!ft_atoi_validate(str, &num) || check_dublicates(num, *stack_a))
				return (0);
			ft_push(num, stack_a);
			str = strnext;
		}
		else
			return (0);
	}
	return (1);
}

int	is_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (-1);
	}
	return (i);
}

int	check_dublicates(long val, t_node *stack)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_atoi_validate(const char *str, long *num)
{
	int					i;
	int					flag;

	i = 0;
	*num = 0;
	flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
		if (ft_isdigit(str[i]))
		{
			*num = *num * 10 + (str[i++] - '0');
			if (*num > INT_MAX || *num < INT_MIN)
				return (0);
		}
		else
			return (0);
	*num = *num * flag;
	return (1);
}
