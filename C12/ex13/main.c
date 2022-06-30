/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:36:06 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 18:36:34 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>
#include <stdio.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;
	t_list	*previous;

	current = *begin_list1;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = begin_list2;
}

int		main(void)
{
	int		index;
	int		*malloced_index;
	t_list	*list;
	t_list	*list2;

	index = 0;
	list = ft_create_elem(0);
	list2 = ft_create_elem(0);
	while (index < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = index;
		ft_list_push_back(&list, (void *)malloced_index);
		ft_list_push_back(&list2, (void *)malloced_index);
		index++;
	}
	ft_list_merge(&list->next, list2->next);
	index = 0;
	list = list->next;
	while (list)
	{
		printf("list[%d]: %d\n", index, *((int *)list->data));
		index++;
		list = list->next;
	}
}
