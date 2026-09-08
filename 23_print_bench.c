/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_print_bench.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:00:35 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/08 21:12:28 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *name, int count)
{
	int	i;

	i = 0;
	while (name[i])
		ft_putchar_fd(name[i++], 2);
	ft_putchar_fd(':', 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

void	print_ops(t_ops *operation)
{
	print_op("sa", operation->sa);
	print_op("sb", operation->sb);
	print_op("ss", operation->ss);
	print_op("pa", operation->pa);
	print_op("pb", operation->pb);
	print_op("ra", operation->ra);
	print_op("rb", operation->rb);
	print_op("rr", operation->rr);
	print_op("rra", operation->rra);
	print_op("rrb", operation->rrb);
	print_op("rrr", operation->rrr);
}

static void	print_percent(float value)
{
	long	scaled;

	scaled = (long)(value * 10000.0 + 0.5);
	ft_putnbr_fd((int)(scaled / 100), 2);
	ft_putchar_fd('.', 2);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(scaled % 100), 2);
	ft_putendl_fd("%", 2);
}

static void	print_strategy(t_bench *bench)
{
	char	*name;
	char	*class;

	name = "unknown";
	class = "n/a";
	if (bench->strategy)
		name = bench->strategy;
	if (bench->complex_class)
		class = bench->complex_class;
	ft_putendl_fd(name, 2);
	ft_putendl_fd(class, 2);
}

void	print_bench(t_ops *operation, t_bench *bench)
{
	ft_putendl_fd("--- benchmark ---", 2);
	print_percent(bench->disorder);
	print_strategy(bench);
	print_op("total", operation->total);
	print_ops(operation);
}