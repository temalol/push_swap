/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:10:28 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/01 19:03:29 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_index(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		i++;
		stack_a = stack_a->next;
	}
}

void	get_commands_sum(t_node *stack_b)
{
	int	sum;

	sum = 0;
	if (stack_b->ra_to_top >= 0)
		sum = sum + stack_b->ra_to_top;
	if (stack_b->rra_to_top >= 0)
		sum = sum + stack_b->rra_to_top;
	if (stack_b->rb_to_top >= 0)
		sum = sum + stack_b->rb_to_top;
	if (stack_b->rrb_to_top >= 0)
		sum = sum + stack_b->rrb_to_top;
	if (stack_b->rr_to_top >= 0)
		sum = sum + stack_b->rr_to_top;
	if (stack_b->rrr_to_top >= 0)
		sum = sum + stack_b->rrr_to_top;
	stack_b->r_sum = sum;
}

void	align_stack_a(t_node **stack_a)
{
	t_node	*min_node;
	int		min_node_ind;
	int		stlen_a;

	min_node = get_min_val(*stack_a, &min_node_ind);
	stlen_a = stacklen_wo_delim(*stack_a);
	if (min_node_ind < stlen_a / 2)
	{
		while ((*stack_a)->val != min_node->val)
		{
			ra(stack_a, 1);
		}
	}
	else
	{
		while ((*stack_a)->val != min_node->val)
		{
			rra(stack_a, 1);
		}
	}
}

void	remove_max_values(t_node *stack_b)
{
	if (stack_b->ra_to_top >= stack_b->rra_to_top)
		stack_b->ra_to_top = 0;
	else
		stack_b->rra_to_top = 0;
	if (stack_b->rb_to_top >= stack_b->rrb_to_top)
		stack_b->rb_to_top = 0;
	else
		stack_b->rrb_to_top = 0;
}

t_node	*push_b(t_node **stack_a, t_node **stack_b)
{
	int		stlen;
	t_node	*stack_a_top;
	t_node	*stack_b_top;

	stlen = stacklen_wo_delim(*stack_a);
	while (stlen--)
	{
		((*stack_a)->stay) ? ra(stack_a, 1) : pb(stack_a, stack_b, 1);
	}
	stack_a_top = (*stack_a);
	stack_b_top = (*stack_b);
	while (stack_a_top->next)
	{
		stack_a_top->delim = 0;
		stack_a_top = stack_a_top->next;
	}
	stack_a_top->delim = 1;
	while (stack_b_top)
	{
		stack_b_top->delim = 0;
		stack_b_top = stack_b_top->next;
	}
	return (stack_a_top);
}
