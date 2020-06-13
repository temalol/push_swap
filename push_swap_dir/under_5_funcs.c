/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_5_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 23:11:53 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/02 21:19:10 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_node **stack_a, long arr[3])
{
	if (arr[0] < arr[2])
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else
	{
		rra(stack_a, 1);
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	(*stack_a)->next->next->delim = 1;
	(*stack_b)->delim = 0;
	(*stack_b)->next->delim = 0;
	push_a(stack_a, stack_b, (*stack_a)->next->next);
	align_stack_a(stack_a);
}

void	sort_three(t_node **stack_a)
{
	long	arr[3];

	arr[0] = (*stack_a)->val;
	arr[1] = (*stack_a)->next->val;
	arr[2] = (*stack_a)->next->next->val;
	if (arr[1] < arr[0] && arr[1] < arr[2])
	{
		(arr[0] < arr[2]) ? (sa(stack_a, 1)) : (ra(stack_a, 1));
		return ;
	}
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
		return ;
	}
	if (arr[0] < arr[1] && arr[1] > arr[2])
	{
		case_3(stack_a, arr);
		return ;
	}
}

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a, 1);
}

int		sort_under_5(t_node **stack_a, t_node **stack_b)
{
	int stlen;

	stlen = stacklen_wo_delim(*stack_a);
	if (stlen == 2)
	{
		sort_two(stack_a);
		return (1);
	}
	if (stlen == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	if (stlen == 5)
	{
		sort_five(stack_a, stack_b);
		return (1);
	}
	return (0);
}
