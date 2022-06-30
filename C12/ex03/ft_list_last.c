/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:24:05 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 21:02:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*node;

	if (begin_list)
	{
		while (begin_list)
		{
			node = begin_list;
			begin_list = begin_list->next;
		}
		return (node);
	}
	return (begin_list);
}
