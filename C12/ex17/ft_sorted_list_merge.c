/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:52:23 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 23:11:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1
, t_list *begin_list2, int (*cmp) ())
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
