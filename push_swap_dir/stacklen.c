/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:34:36 by nmustach          #+#    #+#             */
/*   Updated: 2020/03/25 00:03:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stacklen_wo_delim(t_node *stack_a)
{
	size_t len;

	len = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}

size_t	stacklen(t_node *stack_a)
{
	size_t len;

	len = 0;
	while (stack_a && !stack_a->delim)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}
