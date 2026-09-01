/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:36:03 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/01 19:58:57 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_operation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int total;
}		t_ops;

typedef struct s_bench
{
	float	disorder;
	char	*strategy;
	char	*complex_class;
}	t_bench;

void	ft_free(char **str);
int		is_sorted(t_list **stack);
void	free_stack(t_list **stack);
void	index_stack(t_list **stack);
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
void	print_list(t_list *head);
void	init_stack(t_list **stack, int ac, char **av);

/* Libft functions*/
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(unsigned char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

/* Operations */
void	pa(t_list **stack_a, t_list **stack_b, t_ops *operation);
void	pb(t_list **stack_a, t_list **stack_b, t_ops *operation);
void	ra(t_list **stack, t_ops *operation, int print);
void	rb(t_list **stack, t_ops *operation, int print);
void	rr(t_list **stack_a, t_list **stack_b, t_ops *operation);
void	rra(t_list **stack, t_ops *operation, int print);
void	rrb(t_list **stack, t_ops *operation, int print);
void	rrr(t_list **stack_a, t_list **stack_b, t_ops *operation);
void	sa(t_list **stack, t_ops *operation, int print);
void	sb(t_list **stack, t_ops *operation, int print);
void	ss(t_list **stack_a, t_list **stack_b, t_ops *operation);

/* Algorithm functions */
void	radix_base4(t_list **a, t_list **b, t_ops *operation);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_ops *operation);
void	sort_2(t_list **stack_a, t_ops *operation);
void	sort_3(t_list **stack_a, t_ops *operation);

/* Edited libft functions */
long	ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew_int(int value);

/* Disorder metric */
int		stack_size(t_list *stack);
float	disorder_metric(t_list *stack_a);
void	init_bench(t_bench *bench);
t_bench	calc_disorder(t_list *stack_a);

#endif
