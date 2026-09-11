/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:36:03 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/11 17:27:05 by nisim            ###   ########.fr       */
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
	int	total;
}		t_ops;

typedef enum e_mode
{
	DEFAULT = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH
}	t_mode;

typedef struct s_bench
{
	float	disorder;
	char	*strategy;
	char	*complex_class;
	t_mode	mode;
}	t_bench;

typedef struct s_flags
{
	t_mode	mode;
	int		bench;
}	t_flags;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_ops	*operation;
}	t_stack;

typedef enum e_position
{
	START_A,
	END_A,
	START_B,
	END_B
}	t_pos;

/* General utils*/
void		ft_free(char **str);
int			is_sorted(t_list **stack);
void		free_stack(t_list **stack);
void		index_stack(t_list **stack);
void		ft_error(char *msg);
void		ft_check_args(int ac, char **av, t_flags *flags);
void		init_ops(t_ops *operation);
void		init_stack(t_list **stack, int ac, char **av);
t_mode		is_flag(char *str);
char		**build_args(int ac, char **av);
int			count_args(char **args);
void		extract_flags(char **args, int *count, t_flags *flags);
void		print_bench(t_ops *operation, t_bench *bench);
void		print_ops(t_ops *operation);
void		print_op(char *name, int count);

/* Libft functions*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(unsigned char c);
void		ft_lstadd_back(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);

/* Operations */
void		pa(t_list **stack_a, t_list **stack_b, t_ops *operation);
void		pb(t_list **stack_a, t_list **stack_b, t_ops *operation);
void		ra(t_list **stack, t_ops *operation, int print);
void		rb(t_list **stack, t_ops *operation, int print);
void		rr(t_list **stack_a, t_list **stack_b, t_ops *operation);
void		rra(t_list **stack, t_ops *operation, int print);
void		rrb(t_list **stack, t_ops *operation, int print);
void		rrr(t_list **stack_a, t_list **stack_b, t_ops *operation);
void		sa(t_list **stack, t_ops *operation, int print);
void		sb(t_list **stack, t_ops *operation, int print);
void		ss(t_list **stack_a, t_list **stack_b, t_ops *operation);

/* Algorithm functions */
void		sort_stack(t_list **a, t_list **b, t_bench *bench, t_ops *ops);
void		insertion_sort(t_list **a, t_list **b, t_ops *ops);
void		chunk_sort(t_list **a, t_list **b, t_ops *operation);
void		dual_quicksort(t_list **a, t_list **b, t_ops *operation);
void		adaptive_sort(t_list **a, t_list **b, t_bench *bench, t_ops *ops);

/* Algorithm utils*/
int			pos_of_index(t_list *stack, int index);
int			first_in_chunk(t_list *stack, int hi);
int			last_in_chunk(t_list *stack, int hi);
void		flush_pending(t_list **b, int *pending, t_ops *operation);
void		rotate_b_to(t_list **b, t_ops *operation, int pos);
void		greedy_pop(t_list **a, t_list **b, t_ops *operation);
int			rot_cost(int pos, int size);
int			abs_i(int n);
int			combined(int ca, int cb);
int			pos_of_min(t_list *stack);
int			insert_pos(t_list *a, int value);
void		pop_phase(t_list **a, t_list **b, t_ops *operation);

/* Complex Algorithm*/
int			move_to(t_stack *stack, t_pos from, t_pos to);
int			get_max(t_stack *stack, int size, t_pos current);
int			get_next_index(t_stack *stack, t_pos current);
void		sort_three(t_stack *stack, t_pos current);
void		small_sort(t_stack *stack, int size, t_pos current);

/* Edited libft functions */
long		ft_atoi(const char *nptr);
t_list		*ft_lstnew_int(int value);

/* Disorder metric */
int			stack_size(t_list *stack);
float		disorder_metric(t_list *stack_a);
void		init_bench(t_bench *bench);
t_bench		calc_disorder(t_list *stack_a);

#endif
