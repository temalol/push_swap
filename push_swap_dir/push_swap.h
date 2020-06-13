/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:25:30 by nmustach          #+#    #+#             */
/*   Updated: 2020/04/02 22:33:24 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../checker_dir/checker.h"

int					find_sorted(t_node *stack_a, int flag);
void				get_max_sequence(t_node *stack_a);
void				sort(t_node **stack_a, t_node **stack_b);
t_node				*get_min_val(t_node *stack_a, int *min_node_ind);
void				do_index(t_node *stack_a);
void				remove_max_values(t_node *stack_b);
void				check_for_doubles(t_node *stack_b);
void				get_commands_sum(t_node *stack_b);
size_t				stacklen_wo_delim(t_node *stack_a);
void				ra_rb(t_node *stack_b);
void				rra_rrb(t_node *stack_b);
int					fit_to_first_part(t_node *stack_b,
t_node *stack_a_top, int stlen);
void				fit_to_second_part(t_node *stack_a,
t_node *stack_b, int stlen);
t_node				*get_min_val(t_node *stack_a, int *min_node_ind);
t_node				*get_min_r_sum(t_node *stack_b);
void				align_stack_a(t_node **stack_a);
t_node				*push_b(t_node **stack_a, t_node **stack_b);
int					sort_under_5(t_node **stack_a, t_node **stack_b);
void				push_a(t_node **stack_a, t_node
**stack_b, t_node *stack_a_max);
void				sort_three(t_node **stack_a);

#endif
