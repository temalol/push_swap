/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 19:33:16 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/01 00:44:20 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max_sequence(t_node *stack_a)
{
	int		seq;
	int		max_seq;
	t_node	*max_seq_node;

	seq = 0;
	max_seq = 0;
	while (stack_a)
	{
		seq = find_sorted(stack_a, 0);
		if (seq > max_seq)
		{
			max_seq = seq;
			max_seq_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	find_sorted(max_seq_node, 1);
}

int		find_sorted(t_node *stack_a, int flag)
{
	long	value;
	int		sequence;

	sequence = 1;
	value = stack_a->val;
	if (flag)
		stack_a->stay = 1;
	while (stack_a)
	{
		if (stack_a->val > value)
		{
			value = stack_a->val;
			if (flag)
				stack_a->stay = 1;
			sequence++;
		}
		stack_a = stack_a->next;
	}
	return (sequence);
}
