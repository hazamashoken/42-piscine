/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:37:43 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 18:39:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_list.h"

void	ft_swap_void(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*end;
	bool	swapped;

	if (*begin_list == 0)
		return ;
	swapped = true;
	end = 0;
	while (swapped)
	{
		swapped = false;
		current = *begin_list;
		while (current->next != end)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				ft_swap_void(&(current->data), &(current->next->data));
				swapped = true;
			}
			current = current->next;
		}
		end = current;
	}
}
