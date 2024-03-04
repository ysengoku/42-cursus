/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:28:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 12:46:59 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- includes ---- */
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* --- struct definition --- */
typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

/* --- Check input --- */
int				ft_check_syntax(int ac, char **av);
int				ft_isspace(int c);
int				ft_issign(int c);
int				ft_check_repeat(char **s);
int				ft_check_input(int ac, char **av);

/* --- Initialize stacks --- */
t_stack_node	*ft_newnode(int value);
t_stack_node	*ft_get_lastnode(t_stack_node *stack_head);
int				ft_append_node(t_stack_node **stack, int value);
size_t			ft_stacksize(t_stack_node **stack);
void			ft_init_stack(t_stack_node **stack, char **av, int ac);

/* --- Sort ---*/
int				ft_is_sorted(t_stack_node **stack);
t_stack_node	*ft_get_min_node(t_stack_node **stack);
void			ft_sort_tinystack(t_stack_node **a, t_stack_node **b);
void			ft_radixsort(t_stack_node **a, t_stack_node **b);

/* --- Operations --- */
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/* --- Error & free --- */
void			ft_free_str_arr(char **s);
void			ft_free_stack(t_stack_node **stack);
void			ft_free_and_error(t_stack_node **a, int ac, char **av);
void			ft_error(void);

/* --- Libft functions ---*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
long			ft_atol(const char *s);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);

#endif