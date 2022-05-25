/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:04:38 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/05/25 16:51:54 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

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

void	swap(t_node **head)
{
	t_node	*new_head;

	new_head = (*head)->next;
	(*head)->next = new_head->next;
	new_head->next = *head;
	*head = new_head;
}

void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_b)->next;
	if ((*head_a) == NULL)
	{
		(*head_a) = (*head_b);
		(*head_a)->next = NULL;
	}
	else
		lstadd_front(head_a, *(head_b));
	(*head_b) = tmp;
}

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_a)->next;
	if ((*head_b) == NULL)
	{
		(*head_b) = (*head_a);
		(*head_b)->next = NULL;
	}
	else
		lstadd_front(head_b, *(head_a));
	(*head_a) = tmp;
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

int	find_max(t_node *head)
{
	int	max;

	max = 0;
	while(head != 0)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}

int	find_min(t_node *head)
{
	int	min;

	min = head->value;
	while(head != 0)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}

int	count_nodes(t_node *head_a)
{
	int	i;

	i = 0;
	while (head_a != NULL)
	{
		head_a = head_a->next;
		i++;
	}
	return (i);
}

void	check_a(t_node **head_a, t_node **head_b)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->next == NULL)
	{
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	if ((*head_a)->value > (*head_a)->next->value)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (lstlast((*head_a))->value < (*head_a)->value)
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
	}
	push_b(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}

void	check_b(t_node **head_b)
{
	if ((*head_b) == NULL)
		return ;
	if ((*head_b)->next == NULL)
		return ;
	if (find_min((*head_b)) == (*head_b)->value)
	{
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
	if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		return ;
	}
	if (find_min((*head_b)) == (*head_b)->next->value && (*head_b)->next->next != NULL)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
}

void	check_b_reverse(t_node **head_a, t_node **head_b)
{
	if ((*head_a) == NULL || (*head_a)->next == NULL)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	if ((*head_b)->next == NULL)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
	}
	push_a(head_a, head_b);
	ft_putstr_fd("pa\n", 1);
}

void	show_stack(t_node *head_a, t_node *head_b)
{
	printf("Stack a:\n");
	while (head_a != NULL)
	{
		printf("%d\n", head_a->value);
		head_a = head_a->next;
	}
	printf("Stack b:\n");
	while (head_b != NULL)
	{
		printf("%d\n", head_b->value);
		head_b = head_b->next;
	}
}

void	check_a_reverse(t_node **head_a)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->next == NULL)
		return ;
	if ((*head_a)->value > (*head_a)->next->value)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
	}
}

int	order_a(t_node *head_a)
{
	int	control;
	int	count;

	control = 0;
	count = 0;
	if (head_a == NULL)
		return (control);
	while (head_a->next != NULL)
	{
		if((head_a->value) < (head_a->next->value))
		{
			head_a = head_a->next;
			count++;
		}
		else
			return (control);
	}
	control = 1;
	return (control);
}

int	order_b(t_node *head_b)
{
	int	control;

	control = 0;
	if (head_b == NULL)
		return (control);
	while (head_b->next != NULL)
	{
		if((head_b->value) > (head_b->next->value))
			head_b = head_b->next;
		else
			return (control);
	}
	control = 1;
	return (control);
}

int	first_sort_order_b(t_node *head_b, int sub)
{
	int	count;

	count = 0;
	if (head_b == NULL)
		return (0); // NOT sorted;
	while (count < (sub - 1))
	{
		if(head_b->next == NULL)
			break ;
		if(head_b->value > head_b->next->value)
		{
			count++;
			head_b = head_b->next;
		}
		else
			break ;
	}
	if (count == (sub - 1))
		return (1);
	else
		return (0);
}

int	first_sort_order_a(t_node *head_a, int sub)
{
	int	count;

	count = 0;
	if (head_a == NULL)
		return (0); // NOT sorted;
	while (count < (sub - 1))
	{
		if(head_a->next == NULL)
			break ;
		if(head_a->value < head_a->next->value)
		{
			count++;
			head_a = head_a->next;
		}
		else
			break ;
	}
	if (count == (sub - 1))
		return (1);
	else
		return (0);
}

void	first_sort(t_node **head_a, t_node **head_b, int nodes)
{
	int	a;
	int	b;
	int	sub;

	sub = nodes / 4; // substacks;
	a = nodes - sub;
	b = 0;
	while (a != 0)
	{
		while (1)
		{
			check_a(head_a, head_b);
			if (count_nodes((*head_a)) == a)
				break ;
			check_b(head_b);
			if (count_nodes((*head_a)) == a)
				break ;
		}
		if (first_sort_order_b((*head_b), sub))
		{
			a = a - sub;
			b = b + sub;
		}
		while (1)
		{
			check_a_reverse(head_a);
			if (count_nodes((*head_b)) == b || order_b((*head_b)))
				break ;
			check_b_reverse(head_a, head_b);
			if (count_nodes((*head_b)) == b || order_b((*head_b)))
				break ;
		}
	}
}

void	second_sort(t_node **head_a, t_node **head_b, int nodes)
{
	int	a;
	int	b;
	int	sub;

	sub = nodes / 5;
	a = 0;
	b = nodes - sub;
	while (b != -6)
	{
		while (1)
		{
			check_a_reverse(head_a);
			if (count_nodes((*head_b)) == b)
				break ;
			check_b_reverse(head_a, head_b);
			if (count_nodes((*head_b)) == b)
				break ;
		}
		if (first_sort_order_a((*head_a), sub))
		{
			b = b - sub;
			a = a + sub;
		}
		while (1)
		{
			if (count_nodes((*head_a)) == a)
				break ;
			check_a(head_a, head_b);
			if (count_nodes((*head_a)) == a)
				break ;
			check_b(head_b);
		}
		// if (order_a((*head_a)) && count_nodes((*head_b)) == 0)
		// 	return ;
	}
}

int main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		nodes;

	init_stack(argc, argv, &head_a);
	nodes = count_nodes(head_a); // height of stack;
	first_sort(&head_a, &head_b, nodes);
	// second_sort(&head_a, &head_b, nodes);
	return (0);
}
