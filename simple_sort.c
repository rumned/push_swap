/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:53:27 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/08/27 13:43:07 by mbin-mus         ###   ########.fr       */
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

// still wrong
void sort_3(t_list **stack_a, t_ops *operation)
{
    int last_index;
    *t_list is_largest;
    *t_list hldr;

    last_index = ft_lstsize(*stack_a) - 1;
    hldr = *stack_a;
    is_largest = NULL;
    while (hldr && hldr->next)
    {
        if(hldr->value > is_largest)
            is_largest = hldr;
        hldr = hldr->next;
    }
    if (is_largest->index == 0)
    {
        disorder_metric(*stack_a);
        ra(stack_a, operation, 1);
    }
    else if (is_largest->index == last_index)
        continue;
    else
      {
        disorder_metric(*stack_a);
        rra(stack_a, operation, 1);
    }
}