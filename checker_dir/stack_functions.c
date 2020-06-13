/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:03:34 by nmustach          #+#    #+#             */
/*   Updated: 2020/03/25 00:12:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_node **stack_b, int output)
{
	t_node *next;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		next = (*stack_b)->next;
		(*stack_b)->next = next->next;
		next->next = *stack_b;
		(*stack_b) = next;
		if (output == 1)
			ft_printf("sb\n");
	}
}

void	sa(t_node **stack_a, int output)
{
	t_node *next;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		next = (*stack_a)->next;
		(*stack_a)->next = next->next;
		next->next = *stack_a;
		(*stack_a) = next;
		if (output == 1)
			ft_printf("sa\n");
	}
}

void	pa(t_node **stack_a, t_node **stack_b, int output)
{
	t_node *tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		if (output == 1)
			ft_printf("pa\n");
	}
}

void	pb(t_node **stack_a, t_node **stack_b, int output)
{
	t_node *tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		if (output == 1)
			ft_printf("pb\n");
	}
}
