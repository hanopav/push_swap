/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 05:56:04 by asioud            #+#    #+#             */
/*   Updated: 2024/01/25 13:45:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		display_error("", 1);
	count = check_digits(argc, argv);
	numbers = arg_parse(argc, argv, count);
	if (count <= 1 || check_duplicates_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("", 1);
		display_error(RED"Error\n", 1);
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c)
{
	int		i;
	t_node	*tmp;

	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
	i = c - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, nb[i]);
		i--;
	}
	insertion_sort(nb, c);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = index_of(tmp->data, nb);
		tmp = tmp->next;
	}
}
