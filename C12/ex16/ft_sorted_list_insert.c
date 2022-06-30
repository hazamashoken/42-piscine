/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:45:43 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 23:06:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
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
