/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:58:42 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/05/15 16:19:44 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

// array = {1, 2, 3, 4};

typedef	struct t_nodes
{
	int	value;
	struct t_nodes *next;
} t_node;

t_node	*lstnew(int n)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->value = n;
	new_node->next = NULL;
	return (new_node);
}

t_node	*lstlast(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	if (curr == 0)
		return (curr);
	while (curr->next != 0)
		curr = curr->next;
	return (curr);
}

t_node	*lst_second_last(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	if (curr == 0)
		return (curr);
	while (curr->next->next != NULL)
		curr = curr->next;
	return (curr);
}

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	rotate(t_node **head)
{
	t_node	*new_head;
	t_node	*last;

	last = lstlast(*head);
	new_head = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = new_head;
}

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*second_last;

	last = lstlast(*head);
	second_last = lst_second_last(*head);
	last->next = *head;
	*head = last;
	second_last->next = NULL;
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == 0)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
	new = lstlast(new);
	new->next = NULL;
}

void	swap(t_node **head)
{
	t_node	*new_head;

	new_head = (*head)->next;
	(*head)->next = new_head->next;
	new_head->next = *head;
	*head = new_head;
}

void	init_stack(int argc, char **argv, t_node **node)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		lstadd_back(node, lstnew(n));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_node	*head;

	init_stack(argc, argv, &head);
	// rotate(&head);
	// reverse_rotate(&head);
	// swap(&head);
	// while (head != NULL)
	// {
	// 	printf("%d\n", head->value);
	// 	head = head->next;
	// }
	return (0);
}

// void	swap(int *stack_a, int *stack_b, int s)
// {
// 	int	tmp;
// 	if (s == 0) // s = 0 -> signature for swap_a
// 	{
// 		tmp = stack_a[0];
// 		stack_a[0] = stack_a[1];
// 		stack_a[1] = tmp;
// 	}
// 	else if (s == 1) // s = 1 -> signature for swap_a
// 	{
// 		tmp = stack_b[0];
// 		stack_b[0] = stack_b[1];
// 		stack_b[1] = tmp;
// 	}
// 	else // s = 3 -> swap both stacks
// 	{
// 		tmp = stack_a[0];
// 		stack_a[0] = stack_a[1];
// 		stack_a[1] = tmp;
// 		tmp = stack_b[0];
// 		stack_b[0] = stack_b[1];
// 		stack_b[1] = tmp;
// 	}
// }
