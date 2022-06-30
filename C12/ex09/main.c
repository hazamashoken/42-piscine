/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:23:24 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 18:24:04 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == 0)
		return ;
	(*f)(begin_list->data);
	ft_list_foreach(begin_list->next, f);
}

void	print_element(void *element)
{
	printf("element:: %d\n", *((int *)element));
}

int		main(void)
{
	int		*index;
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
	ft_list_foreach(list, &print_element);
}
