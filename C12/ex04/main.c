/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:29:48 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 17:20:42 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
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


void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;

	node = *begin_list;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}


void display(t_list *begin_list)
{
    while(begin_list != NULL)
    {
      printf("%d\n", *(int *)begin_list->data);
      begin_list = begin_list->next;
    }
}
int main() 
{
  t_list *head;
  head = (t_list*)malloc(sizeof(t_list));
  int a =1;
  int b=3;
  int c = 37;
  void *ptr=&a;
  void *pt = &b;
  void *p = &c;
  head = ft_create_elem(ptr);
  head->next= ft_create_elem(pt);
  ft_list_push_back(&head, p);
  display(head);
  return 0;
}
