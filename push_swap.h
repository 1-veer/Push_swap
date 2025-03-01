/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:20:52 by abougati          #+#    #+#             */
/*   Updated: 2025/02/28 22:18:30 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_chunk
{
	int				start;
	int				end;
}					t_chunk;

typedef struct s_cost
{
	int				index;
	int				moves;
	int				is_ra;
}					t_cost;

typedef struct s_max
{
	int				value;
	int				moves;
	int				position;
}					t_max_cost;

typedef struct s_min
{
	int				value;
	int				moves;
	int				position;
}					t_min_cost;

void				initialize_a(t_stack **a, char **av);
long				ft_atol(const char *str);
int					append_to_stack(t_stack **a, int n);
int					duplication_error(t_stack *a, int n);
int					syntax_error(char *str);
void				handle_error(t_stack **a, char **av);
void				free_a(t_stack **a);
void				free_av(char **av);

int					already_sorted(t_stack *a);
int					stack_size(t_stack *a);
t_stack				*ft_lstlast(t_stack *lst);

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
int					ft_strcmp(char *s1, char *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);

void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				pb(t_stack **head_a, t_stack **head_b);
void				pa(t_stack **head_a, t_stack **head_b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				sort_2_or_3(t_stack **a);
t_stack				*find_highest(t_stack *a);

int					*sort_array(t_stack *a);
void				sorted_in_reverse(t_stack **a);
t_max_cost			get_max(t_stack *stack, int size);
void				sort_4_or_5(t_stack **a, t_stack **b);
void				push_back_to_a(t_stack **b, t_stack **a);
void				main_sort(t_stack **a, t_stack **b);
int					is_smaller(int a, int b);
int					is_in_chunk(int num, t_chunk chunk);
void				swap_em(int *xp, int *yp);
int					append_node(t_stack **stack, int nbr);
t_stack				*find_last_node(t_stack *head);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char				*get_next_line(int fd);
char				*read_and_add(int fd, char *buffer);
char				*extract_line(char *buffer);
char				*adjust_buffer(char *buffer);

int					check_for_endline(char *buff);
char				*ft_join(char **s1, char *s2);
char				*dupp(char *s);
int					get_len(char *s);

int					checker(t_stack **a, t_stack **b);
void				check_sa(t_stack **a);
void				check_sb(t_stack **b);
void				check_ss(t_stack **a, t_stack **b);
void				check_pa(t_stack **a, t_stack **b);
void				check_pb(t_stack **a, t_stack **b);
void				check_ra(t_stack **a);
void				check_rb(t_stack **b);
void				check_rr(t_stack **a, t_stack **b);
void				check_rra(t_stack **a);
void				check_rrb(t_stack **b);
void				check_rrr(t_stack **a, t_stack **b);
void				error_clean(t_stack **a, t_stack **b, char *av);
void				check_rev_rotate(t_stack **a);
void				check_rotate(t_stack **a);
void				check_swap(t_stack **a);
int					ft_strcmp(char *s1, char *s2);
char				*helper(char **buffer);
char				*copy(char *buffer, char *line, int i);

#endif