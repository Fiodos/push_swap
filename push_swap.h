/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:35:43 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/25 11:01:56 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct s_nodes
{
	int				value;
	struct s_nodes	*next;
}	t_node;

t_node	*lstnew(int n);

t_node	*lstlast(t_node *lst);

t_node	*lst_second_last(t_node *lst);

void	lstadd_front(t_node **lst, t_node *new_node);

void	lstadd_back(t_node **lst, t_node *new_node);

void	rotate(t_node **head);

void	reverse_rotate(t_node **head);

void	swap(t_node **head);

void	push_a(t_node **head_a, t_node **head_b);

void	push_b(t_node **head_a, t_node **head_b);

void	init_stack(int argc, char **argv, t_node **node);

int		count_nodes(t_node *head_a);

int		calc_steps(t_node *head, int max, int *rota);

void	push_first_element(t_node **head_a, t_node **head_b, int max);

void	get_range(int *scan_range, int *range, int argc);

int		scan_top(t_node *head, int scan_range);

int		scan_bot(t_node *head, int scan_range);

int		find_max_top(t_node *head, int range);

int		find_max_bot(t_node *head, int range);

int		find_max(t_node *head);

int		order_a(t_node *head_a);

void	check_a(t_node **head_a);

int		new_check_a(t_node *head_a, t_node *head_b);

void	check_b_reverse(t_node **head_a, t_node **head_b);

void	sort_small_stack(t_node **head_a, t_node **head_b);

void	sort_b_backwards(t_node **head_a, t_node **head_b);

int		get_max(t_node *head_a, int range);

int		get_bigger_element(t_node **head_a, t_node **head_b, int range);

void	element_found(t_node **head_a, t_node **head_b);

void	get_next_element(t_node **head_a, int scan_range);

void	is_duplicate(t_node *head, int n);

void	split_argv(char **argv, t_node **node);

int		find_sec_max(t_node *head, int max);

void	rotate_to_max(t_node **head_b, int max, int rota);

void	push_and_check(t_node **head_a, t_node **head_b);

#endif
