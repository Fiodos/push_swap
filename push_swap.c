/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:58:42 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/05/17 17:42:36 by fyuzhyk          ###   ########.fr       */
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

void	push_b(t_node **head_a, t_node **head_b)
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

int	check_second_last_max(t_node *head, int argc, int max)
{
	int	i;
	int	count;

	i = 0;
	count = count_nodes(head);
	while(i < (count - 2))
	{
		head = head->next;
		i++;
	}
	if (head->value == max)
		return (1);
	return (0);
}

int	check_second_last_min(t_node *head, int argc, int min)
{
	int	i;

	i = 0;
	while(i < (argc - 3))
	{
		head = head->next;
		i++;
	}
	if (head->value == min)
		return (1);
	return (0);
}

int	check_min_last(t_node *head, int min)
{
	if (lstlast(head)->value == min)
		return (1);
	return (0);
}

void	check_position_max_a(t_node **head_a, int max, int argc)
{
	if ((*head_a)->value == max) // if top of stack is max;
	{
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
		return ;
	}
	if((*head_a)->next->value == max) // if second_top is max;
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		rotate(head_a);
		return ;
	}
	if (check_second_last_max((*head_a), argc, max)) // if second_last is max;
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
		return ;
	}
}

void	check_position_max_b(t_node **head_b, int max, int argc)
{
	if (lstlast((*head_b))->value == max)
	{
		reverse_rotate(head_b);
		ft_putstr_fd("rrb\n", 1);
		return ;
	}
}

void	check_position_min_b(t_node **head_b, int min, int argc)
{
	if ((*head_b)->value == min)
	{
		if ((*head_b)->next == NULL)
			return ;
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
	if ((*head_b)->next->value == min)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
	if (check_second_last_min((*head_b), argc, min))
	{
		reverse_rotate(head_b);
		ft_putstr_fd("rrb\n", 1);
		return ;
	}
}

void	check_position_min_a(t_node **head_a, t_node **head_b, int min)
{
	if ((*head_a)->value == min)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	if ((*head_a)->next->value == min)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	if (lstlast((*head_a))->value == min)
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
		push_a(head_a, head_b);
	}
}

void	check_a(t_node **head_a, t_node **head_b)
{
	if ((*head_a)->value < (*head_a)->next->value) // if first element is smaller;
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
	}
}

void	check_b(t_node **head_a, t_node **head_b)
{
	if ((*head_b)->next == NULL)
		return ;
	if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
	}
	else
		return ;
}

void	check_b_reverse(t_node **head_a, t_node **head_b)
{
	if ((*head_b)->next == NULL)
	{
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	if ((*head_b)->value > (*head_b)->next->value) // if first element is bigger;
	{
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	else
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
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

int main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		max;
	int		min;

	init_stack(argc, argv, &head_a);
	min = find_min(head_a);
	max = find_max(head_a);
	while(1)
	{
		check_a(&head_a, &head_b);
		if (count_nodes(head_a) == 2)
			break;
		check_b(&head_a, &head_b);
		if (count_nodes(head_a) == 2)
			break;
		check_position_max_a(&head_a, max, argc);
		if (count_nodes(head_a) == 2)
			break;
		check_position_min_a(&head_a, &head_b, min);
		show_stack(head_a, head_b);
		if (count_nodes(head_a) == 2)
			break;
		check_position_max_b(&head_b, max, argc);
		if (count_nodes(head_a) == 2)
			break;
		check_position_min_b(&head_b, min, argc);
		if (count_nodes(head_a) == 2)
			break;
	}
	// printf("\n--------\n");
	// show_stack(head_a, head_b);
	// printf("\n--------\n");
	// printf("start of second the second part:\n");
	// while (1)
	// {
	// 	check_b_reverse(&head_a, &head_b);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// 	check_position_max_a(&head_a, max, argc);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// 	check_position_min_a(&head_a, &head_b, min);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// 	check_position_max_b(&head_b, max, argc);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// 	check_position_min_b(&head_b, min, argc);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// }
	// printf("\n--------\n");
	// show_stack(head_a, head_b);
	// printf("\n--------\n");
	// check_a(&head_a, &head_b);
	// check_b_reverse(&head_a, &head_b);
	// check_position_max_a(&head_a, max, argc);
	// check_position_min_a(&head_a, &head_b, min);
	// check_position_max_b(&head_b, max, argc);
	// check_position_min_b(&head_b, min, argc);
	// check_b_reverse(&head_a, &head_b);
	// check_position_max_a(&head_a, max, argc);
	// check_position_min_a(&head_a, &head_b, min);
	// check_position_max_b(&head_b, max, argc);
	// check_position_min_b(&head_b, min, argc);
	// check_b(&head_a, &head_b);
	// check_position_max_a(&head_a, max, argc);
	// check_position_min_a(&head_a, &head_b, min);
	// check_position_max_b(&head_b, max, argc);
	// check_position_min_b(&head_b, min, argc);
	// check_position_min_b(&head_b, min, argc);
	// check_position_min(&head_a, &head_b, min);
	// check_position_max(&head_a, max, argc);
	// push_a(&head_a, &head_b);
	// push_b(&head_a, &head_b);
	// rotate(&head);
	// reverse_rotate(&head);
	// swap(&head);
	// printf("Here comes stack a\n");
	// while (head_a != NULL)
	// {
	// 	printf("%d\n", head_a->value);
	// 	head_a = head_a->next;
	// }
	// printf("Here comes stack b\n");
	// while (head_b != NULL)
	// {
	// 	printf("%d\n", head_b->value);
	// 	head_b = head_b->next;
	// }
	return (0);
}

/*
	pre-sorting:
	1) Store the max value
	2) Store the min value
	sorting:
	1) Check if the smallest/largest int is on top/bottom of stack a; (actually do this every time a change occurs on both stacks!);
	--> If smallest = first, push to b;
	--> If smallest = second, swap with first and push to b;
	--> If smallest = last, reverse rotate and push to b;
	--> If biggest = first, push list one up (biggest becomes last element);
	--> If biggest = second, swap and then push one up;
	--> If biggest = second_last, push list one down;
	2) Compare first to elements. Put the smaller one to the top, and push to b;
	3) Compare b's elements, put the biggest always to the top;
	4) If there are only 2 elements left in stack a, "reverse" the sorting flow from b to a;
	but still do all the operations.
	So I need to check the amount of nodes in stack a after every operation;
	Also if 2 conditions are true at the same time, we need to call both functions!; (I will implement this later on);
	Terminate the operation if head_a == NULL;
	Implement the function which compares the first two elements of a, puts the smaller one
	to the top and pushes it to b!
	Implement the function which compares the first elements of b and puts the bigger one at the top;
	(maybe in the end it might improve the algo if every element is directly send from b to a);
	The algo only works if the max amount of integers is 5;
*/
