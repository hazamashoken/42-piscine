/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:29:48 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 17:21:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
