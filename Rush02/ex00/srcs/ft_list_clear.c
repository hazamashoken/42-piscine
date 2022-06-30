/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:48:42 by scharuka          #+#    #+#             */
/*   Updated: 2022/06/26 14:39:57 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
@brief	to erase the linked list
@brief	free each list then move to the next one to free it next
@params	t_dict**	begin_with	the start of linked list
@return	void
*/

void	ft_list_clear(t_dict **begin_list)
{
	t_dict	*node;
	t_dict	*temp;

	node = *begin_list;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp->literal);
		free(temp);
	}
}
