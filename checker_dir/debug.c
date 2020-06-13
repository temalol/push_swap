/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:14:04 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/01 16:38:55 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printstack(t_node *stack_a, t_node *stack_b)
{
	ft_printf("\n\nA          B");
	ft_printf("\n------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a != NULL)
			ft_printf("%ld|%ld|%ld|   |    ", stack_a->val,
			stack_a->stay, stack_a->delim);
		else
			ft_printf("      |     ");
		if (stack_b != NULL)
			ft_printf("%d|ra:%d rra:%d rb:%d rrb:%d rr:%d rrr:%d sum:%d",
			stack_b->val, stack_b->ra_to_top, stack_b->rra_to_top,
			stack_b->rb_to_top, stack_b->rrb_to_top, stack_b->rr_to_top,
			stack_b->rrr_to_top, stack_b->r_sum);
		else
			ft_printf("          ");
		ft_printf("\n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_printf("\n");
}
