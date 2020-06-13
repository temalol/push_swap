/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:46:52 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/02 21:19:32 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (!push_values_to_stack(argc, argv, &stack_a))
			return (std_err(stack_a, stack_b));
		if (stack_a->next)
		{
			if (!read_instructions(&stack_a, &stack_b))
				return (std_err(stack_a, stack_b));
			if (is_sorted(stack_a, stack_b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		free_both_stacks(stack_a, stack_b);
	}
	return (0);
}
