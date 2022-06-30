/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:52:23 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 23:10:26 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp) ())
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*prev;
	t_list	*temp;

	while (begin_list2 != 0)
	{
		prev = 0;
		elem = *begin_list1;
		while (elem != 0 && (*cmp)(begin_list2->data, elem->data) > 0)
		{
			prev = elem;
			elem = elem->next;
		}
		temp = begin_list2->next;
		begin_list2->next = elem;
		if (prev == 0)
			*begin_list1 = begin_list2;
		else
			prev->next = begin_list2;
		begin_list2 = temp;
	}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc (sizeof(t_list));
	if (elem != NULL)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elem;
	t_list	*list;
	int		i;

	i = 0;
	list = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		if (elem != 0)
		{
			elem->next = list;
			list = elem;
		}
		i++;
	}
	return (list);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	temp;

	elem1 = *begin_list;
	while (elem1 != 0)
	{
		elem2 = elem1->next;
		while (elem2 != 0)
		{
			if ((*cmp)(elem1->data, elem2->data) > 0)
			{
				temp.data = elem1->data;
				elem1->data = elem2->data;
				elem2->data = temp.data;
			}
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
}

void	ft_list_print(t_list *list)
{
	int	size;

	if (list == 0)
		printf("empty");
	size = 0;
	while (list != 0)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
		size++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*l;
	t_list	*e;
	int		i;

	printf("\nList 1:\n");
	l = ft_list_push_strs(argc, argv);
	ft_list_print(l);
	printf("\nSorted list 1:\n");
	ft_list_sort(&l, &strcmp);
	ft_list_print(l);
	printf("\nUnsorted list 2:\n");
	e = ft_list_push_strs(argc, argv);
	ft_list_print(e);
	printf("\nSorted list merge of 1 and 2:\n");
	ft_sorted_list_merge(&l, e, &strcmp);
	ft_list_print(l);
	return (0);
}
