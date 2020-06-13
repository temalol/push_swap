/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 21:56:29 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/02 21:55:12 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fit_value(t_node *stack_a, t_node *stack_b,
t_node *stack_a_top, int stlen)
{
	if (stack_a_top->index != 0)
		if (!fit_to_first_part(stack_b, stack_a_top, stlen))
			return (0);
	fit_to_second_part(stack_a, stack_b, stlen);
	return (0);
}

void	fit(t_node *stack_a, t_node *stack_b)
{
	int		stlen_a;
	int		stlen_b;
	int		stack_b_ind;
	t_node	*min_node;
	int		min_node_ind;

	stack_b_ind = 0;
	min_node = get_min_val(stack_a, &min_node_ind);
	stlen_a = stacklen_wo_delim(stack_a);
	stlen_b = stacklen_wo_delim(stack_b);
	while (stack_b)
	{
		fit_value(stack_a, stack_b, min_node, stlen_a);
		stack_b->rb_to_top = stack_b_ind;
		stack_b->rrb_to_top = stlen_b - stack_b_ind;
		remove_max_values(stack_b);
		check_for_doubles(stack_b);
		get_commands_sum(stack_b);
		stack_b_ind++;
		stack_b = stack_b->next;
	}
}

void	move_stacks(t_node **stack_a, t_node **stack_b, t_node *min_mv_n)
{
	while (min_mv_n->ra_to_top--)
		ra(stack_a, 1);
	while (min_mv_n->rra_to_top--)
		rra(stack_a, 1);
	while (min_mv_n->rb_to_top--)
		rb(stack_b, 1);
	while (min_mv_n->rrb_to_top--)
		rrb(stack_b, 1);
	while (min_mv_n->rr_to_top--)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		ft_printf("rr\n");
	}
	while (min_mv_n->rrr_to_top--)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		ft_printf("rrr\n");
	}
	pa(stack_a, stack_b, 1);
}

void	push_a(t_node **stack_a, t_node **stack_b, t_node *stack_a_max)
{
	t_node	*min_mv_node;
	t_node	*max_val_node;

	max_val_node = stack_a_max;
	while (*stack_b)
	{
		do_index(*stack_a);
		fit(*stack_a, *stack_b);
		min_mv_node = get_min_r_sum(*stack_b);
		if (max_val_node->val < min_mv_node->val)
		{
			max_val_node->delim = 0;
			min_mv_node->delim = 1;
			max_val_node = min_mv_node;
		}
		move_stacks(stack_a, stack_b, min_mv_node);
	}
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*stack_a_max;

	if (sort_under_5(stack_a, stack_b))
		return ;
	get_max_sequence(*stack_a);
	stack_a_max = push_b(stack_a, stack_b);
	push_a(stack_a, stack_b, stack_a_max);
	align_stack_a(stack_a);
}
