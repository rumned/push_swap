/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:53:27 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/01 20:05:01 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_list **stack_a, t_ops *operation)
{
    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    if((*stack_a)->index > (*stack_a)->next->index)
    {
        disorder_metric(*stack_a);
        sa(stack_a, operation, 1);
    }
}

void sort_3(t_list **stack_a, t_ops *operation)
{
    int     last_index;
    int     largest_val;
    int     largest_pos;
    int     pos;
    t_list  *hldr;
 
    last_index = ft_lstsize(*stack_a) - 1;
    hldr = *stack_a;
    largest_val = (*stack_a)->value;
    pos = 0;
    largest_pos = 0;
    while (hldr)
    {
        if (hldr->value > largest_val)
        {
            largest_val = hldr->value;
            largest_pos = pos;
        }
        hldr = hldr->next;
        pos++;
    }
    if (largest_pos == 0)
    {
        disorder_metric(*stack_a);
        ra(stack_a, operation, 1);
    }
    else if (largest_pos != last_index)
    {
        disorder_metric(*stack_a);
        rra(stack_a, operation, 1);
    }
    if ((*stack_a)->value > (*stack_a)->next->value)
    {
        disorder_metric(*stack_a);
        sa(stack_a, operation, 1);
    }
}