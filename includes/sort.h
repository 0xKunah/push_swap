/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:46 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 11:36:27 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# ifndef TYPES_H
#  include "types.h"
# endif

void	sort_little_stacks(t_stacks *stacks);
void	sort_big_stacks(t_stacks *stacks);
void	quick_sort(t_stacks *stacks);
void	move_min_a_to_b(t_stacks *stacks);
size_t	find_min(t_stack *stack);
void	sort_three_stack_a(t_stacks *stacks);

#endif
