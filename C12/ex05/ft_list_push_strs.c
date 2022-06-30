/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:27:45 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 17:32:14 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*node;

	if (size <= 0)
		return (0);
	node = ft_create_elem((void *)strs[size - 1]);
	node->next = ft_list_push_strs(size - 1, strs);
	return (node);
}
