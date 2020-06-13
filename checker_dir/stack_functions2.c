/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 21:31:00 by nmustach          #+#    #+#             */
/*   Updated: 2020/03/25 00:12:13 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		std_err(t_node *stack_a, t_node *stack_b)
{
	free_both_stacks(stack_a, stack_b);
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

void	ra(t_node **stack_a, int output)
{
	t_node *last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = *stack_a;
		*stack_a = (*stack_a)->next;
		last = last->next;
		last->next = NULL;
		if (output == 1)
			ft_printf("ra\n");
	}
}

void	rb(t_node **stack_b, int output)
{
	t_node *last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = *stack_b;
		*stack_b = (*stack_b)->next;
		last = last->next;
		last->next = NULL;
		if (output == 1)
			ft_printf("rb\n");
	}
}

void	rra(t_node **stack_a, int output)
{
	t_node	*last;
	t_node	*prev_last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		if (output == 1)
			ft_printf("rra\n");
	}
}

void	rrb(t_node **stack_b, int output)
{
	t_node	*last;
	t_node	*prev_last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		if (output == 1)
			ft_printf("rrb\n");
	}
}
