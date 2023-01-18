/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:34:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 07:34:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACKS_H
# define STACKS_H

# ifndef TYPES_H
#  include "types.h"
# endif

t_stack		*create_node(int value);
t_stack		*get_last_node(t_stack *stack);
void		push_node(t_stack **stack, t_stack *node);
void		unshift_node(t_stack **stack, t_stack *node);
int			get_index(t_stack *stack, int value);
void		index_stack(t_stack **stack);
t_stacks	init_stacks(char **args);
#endif