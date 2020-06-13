/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:04:52 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/01 18:22:24 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_r_sum(t_node *stack_b)
{
	t_node	*min_mv_node;
	int		min_mv_val;

	min_mv_node = stack_b;
	min_mv_val = stack_b->r_sum;
	while (stack_b)
	{
		if (stack_b->r_sum < min_mv_val)
		{
			min_mv_val = stack_b->r_sum;
			min_mv_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (min_mv_node);
}

t_node	*get_min_val(t_node *stack_a, int *min_node_ind)
{
	t_node		*min_node;
	int			min_val;
	int			node_cnt;

	node_cnt = 0;
	*min_node_ind = 0;
	min_node = stack_a;
	min_val = stack_a->val;
	while (stack_a)
	{
		if (stack_a->val < min_val)
		{
			min_val = stack_a->val;
			min_node = stack_a;
			*min_node_ind = node_cnt;
		}
		node_cnt++;
		stack_a = stack_a->next;
	}
	return (min_node);
}
