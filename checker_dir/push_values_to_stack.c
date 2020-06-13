/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_values_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:08:15 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/03 02:55:01 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_both_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node *tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}
}

void	stack_rev(t_node **stack)
{
	t_node *tmpnext;
	t_node *tmp2;

	if ((*stack)->next != NULL)
	{
		tmpnext = (*stack)->next;
		tmp2 = (*stack);
		(*stack)->next = NULL;
		(*stack) = tmpnext;
		while ((*stack)->next)
		{
			tmpnext = (*stack)->next;
			(*stack)->next = tmp2;
			tmp2 = (*stack);
			(*stack) = tmpnext;
		}
		(*stack)->next = tmp2;
	}
}

int		ft_push(long val, t_node **stack_a)
{
	t_node *tmp;

	if ((*stack_a) == NULL)
	{
		*stack_a = malloc(sizeof(t_node));
		if (*stack_a == NULL)
			exit(0);
		(*stack_a)->next = NULL;
		(*stack_a)->val = val;
		(*stack_a)->stay = 0;
		return (1);
	}
	tmp = malloc(sizeof(t_node));
	if (tmp == NULL)
		exit(0);
	tmp->val = val;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	(*stack_a)->stay = 0;
	(*stack_a)->delim = 0;
	return (1);
}

int		string_args_case(char **argv, t_node **stack_a)
{
	int i;

	i = is_number(argv[1]);
	if (i > 0 && argv[1][i + 1] && (!argv[1][i] || argv[1][i] == ' '))
	{
		if (!parse_and_push(argv[1], stack_a))
			return (0);
		stack_rev(stack_a);
		return (1);
	}
	return (0);
}

int		push_values_to_stack(int argc, char **argv, t_node **stack_a)
{
	int		argcnt;
	long	num;

	argcnt = 1;
	if (argc == 2)
		return (string_args_case(argv, stack_a));
	while (argcnt <= argc - 1)
	{
		if (!ft_atoi_validate(argv[argcnt], &num) ||
		check_dublicates(num, *stack_a))
			return (0);
		ft_push(num, stack_a);
		argcnt++;
	}
	stack_rev(stack_a);
	return (1);
}
