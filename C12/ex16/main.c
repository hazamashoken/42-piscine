/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:45:43 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 23:05:53 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int    ft_strcmp(void *data1, void *data2)
{
    return (*(int *)data1 - *(int *)data2);
}

void ft_sorted_list_insert(t_list **begin_list,void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*prev;
	t_list	*temp;

	prev = 0;
	elem = *begin_list;
	while (elem != 0 && (*cmp)(data, elem->data) > 0)
	{
		prev = elem;
		elem = elem->next;
	}
	temp = ft_create_elem(data);
	temp->next = elem;
	if (prev == 0)
		*begin_list = temp;
	else
		prev->next = temp;
}

void display(t_list *head)
{
    while(head != NULL)
    {
        printf("%d ",*(int *)head->data);
        head = head->next;
    }
}

int main()
{
    int a = 40, b = 20, x= 50, o = 10;
    void*    d =&a;
    void*    e =&b;
    void*    i = &x;
    void*    q = &o;
    t_list* head=(t_list*)malloc(sizeof(t_list));
    head = ft_create_elem(d);
    head->next = ft_create_elem(e);
    head->next->next = ft_create_elem(i);
    display(head);
    printf("\n");
    ft_sorted_list_insert(&head, q, ft_strcmp);
    display(head);
    return (0);
}

