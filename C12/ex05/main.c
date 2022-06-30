/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:27:45 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 17:36:36 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list* new_node;
	
	new_node = (t_list*)malloc(sizeof(t_list));
	if(new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return (new_node);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*node;

	if (size <= 0)
		return (0);
	node = ft_create_elem((void *)strs[size - 1]);
	node->next = ft_list_push_strs(size - 1, strs);
	return (node);
}

int        main(void)
{
    t_list    *begin;
    char    **strs;
    begin = (t_list *)malloc(sizeof(t_list));
    strs = malloc(sizeof(char*) * 3);
    strs[0] = malloc(sizeof(char*) * 8);
    strs[1] = malloc(sizeof(char*) * 11);
    strs[0] = "tliangso";
    strs[1] = "piscine 42 ";
    begin = ft_list_push_strs(2, strs);
    while (begin)
    {
        printf("%s", (char *)begin->data);
        begin = begin->next;
    }
    return (0);
}
