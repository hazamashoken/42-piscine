/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:34:11 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 22:58:30 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
				void (*free_fct)(void *))
{
	t_list	*elem;
	t_list	*prev;

	prev = 0;
	elem = *begin_list;
	while (elem != 0)
	{
		if ((*cmp)(elem->data, data_ref) == 0)
		{
			if (elem == *begin_list)
				*begin_list = elem->next;
			else
				prev->next = elem->next;
			(*free_fct)(elem->data);
			free(elem);
			elem = *begin_list;
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}

void	delete_element(void *element)
{
	printf("element:: %d\n", *((int *)element));
	free(element);
}

int		compare_modulo(void *data, void *data_ref)
{
	return (*((int *)data) % *((int *)data_ref));
}

int		main(void)
{
	int		*index;
	int		*modulo;
	int		*malloced_index;
	t_list	*list;

	index = malloc(sizeof(int));
	*index = 0;
	list = ft_create_elem(index);
	while ((*index += 1) < 10)
	{
		malloced_index = malloc(sizeof(int));
		*malloced_index = *index;
		ft_list_push_back(&list, (void *)malloced_index);
	}
	modulo = malloc(sizeof(int));
	*modulo = 2;
	ft_list_remove_if(&list, modulo, &compare_modulo, &delete_element);
	list = list->next;
	*index = 0;
	while (list)
	{
		printf("list[%d] = %d\n", *index, *((int *)list->data));
		list = list->next;
		*index += 1;
	}
}
