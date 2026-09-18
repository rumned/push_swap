/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <nisim@student.42penang.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 22:08:49 by nisim             #+#    #+#             */
/*   Updated: 2026/09/18 16:20:02 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_ops	*operation;
}	t_stack;

int			is_sorted(t_list **stack);
int			is_ops(char *input);
void		ft_free(char **str);
char		*get_next_line(int fd);
void		free_stack(t_list **stack);
char		**ft_split(char const *s, char c);
void		ft_check_args(int argc, char **argv);
void		init_stack(t_list **stack, int ac, char **av);
int			ft_strcmp(const char *s1, const char *s2);
t_list		*ft_lstnew_int(int value);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		execute_operation(t_stack *stack, char **input);
void		pa(t_list **stack_a, t_list **stack_b, t_ops *operation, int print);
void		pb(t_list **stack_a, t_list **stack_b, t_ops *operation, int print);
void		ra(t_list **stack, t_ops *operation, int print);
void		rb(t_list **stack, t_ops *operation, int print);
void		rr(t_list **stack_a, t_list **stack_b, t_ops *operation, int print);
void		rra(t_list **stack, t_ops *operation, int print);
void		rrb(t_list **stack, t_ops *operation, int print);
void		rrr(t_list **stack_a, t_list **stack_b, t_ops *operation,
				int print);
void		sa(t_list **stack, t_ops *operation, int print);
void		sb(t_list **stack, t_ops *operation, int print);
void		ss(t_list **stack_a, t_list **stack_b, t_ops *operation, int print);

#endif
