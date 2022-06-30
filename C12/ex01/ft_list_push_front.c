/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:55:00 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 20:55:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (*begin_list)
	{
		new_node = ft_create_elem(data);
		new_node->next = *begin_list;
		*begin_list = new_node;
	}
	else
		*begin_list = ft_create_elem(data);
}
