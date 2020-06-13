/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:47:29 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/02 21:54:25 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_doubles(t_node *stack_b)
{
	stack_b->rrr_to_top = 0;
	stack_b->rr_to_top = 0;
	if (stack_b->ra_to_top > 0 && stack_b->rb_to_top > 0)
		ra_rb(stack_b);
	if (stack_b->rra_to_top > 0 && stack_b->rrb_to_top > 0)
		rra_rrb(stack_b);
}

void	ra_rb(t_node *stack_b)
{
	if (stack_b->ra_to_top > stack_b->rb_to_top)
	{
		stack_b->rr_to_top = stack_b->rb_to_top;
		stack_b->ra_to_top = stack_b->ra_to_top - stack_b->rb_to_top;
		stack_b->rb_to_top = 0;
	}
	if (stack_b->ra_to_top < stack_b->rb_to_top)
	{
		stack_b->rr_to_top = stack_b->ra_to_top;
		stack_b->rb_to_top = stack_b->rb_to_top - stack_b->ra_to_top;
		stack_b->ra_to_top = 0;
	}
	if (stack_b->ra_to_top == stack_b->rb_to_top)
	{
		stack_b->rr_to_top = stack_b->rb_to_top;
		stack_b->ra_to_top = 0;
		stack_b->rb_to_top = 0;
	}
}

void	rra_rrb(t_node *stack_b)
{
	if (stack_b->rra_to_top > stack_b->rrb_to_top)
	{
		stack_b->rrr_to_top = stack_b->rrb_to_top;
		stack_b->rra_to_top = stack_b->rra_to_top - stack_b->rrb_to_top;
		stack_b->rrb_to_top = 0;
	}
	if (stack_b->rrb_to_top > stack_b->rra_to_top)
	{
		stack_b->rrr_to_top = stack_b->rra_to_top;
		stack_b->rrb_to_top = stack_b->rrb_to_top - stack_b->rra_to_top;
		stack_b->rra_to_top = 0;
	}
	if (stack_b->rra_to_top == stack_b->rrb_to_top)
	{
		stack_b->rrr_to_top = stack_b->rrb_to_top;
		stack_b->rra_to_top = 0;
		stack_b->rrb_to_top = 0;
	}
}

int		fit_to_first_part(t_node *stack_b,
t_node *stack_a_top, int stlen)
{
	long val_to_fit;

	val_to_fit = stack_b->val;
	if (val_to_fit < stack_a_top->val)
	{
		stack_b->ra_to_top = stack_a_top->index;
		stack_b->rra_to_top = stlen - stack_b->ra_to_top;
		return (0);
	}
	while (stack_a_top->next)
	{
		if (val_to_fit > stack_a_top->val &&
		val_to_fit < stack_a_top->next->val)
		{
			stack_b->ra_to_top = stack_a_top->index + 1;
			stack_b->rra_to_top = stlen - stack_b->ra_to_top;
			return (0);
		}
		stack_a_top = stack_a_top->next;
	}
	return (1);
}

void	fit_to_second_part(t_node *stack_a, t_node *stack_b, int stlen)
{
	long	val_to_fit;

	val_to_fit = stack_b->val;
	if (val_to_fit < stack_a->val)
	{
		stack_b->ra_to_top = stack_a->index;
		stack_b->rra_to_top = stlen - stack_b->ra_to_top;
		return ;
	}
	while (!stack_a->delim)
	{
		if (val_to_fit > stack_a->val && val_to_fit < stack_a->next->val)
		{
			stack_b->ra_to_top = stack_a->index + 1;
			stack_b->rra_to_top = stlen - stack_b->ra_to_top;
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_a->val < val_to_fit)
	{
		stack_b->ra_to_top = stack_a->index + 1;
		stack_b->rra_to_top = stlen - stack_b->ra_to_top;
		return ;
	}
}
