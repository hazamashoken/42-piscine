/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:08:25 by ybayart           #+#    #+#             */
/*   Updated: 2022/06/26 15:29:53 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_list_push_front(t_dict **liste, int n, int suf, char *lit)
{
	t_dict	*push;

	if (liste)
	{
		push = ft_create_elem(n, suf, lit);
		if (push == NULL)
			return (0);
		push->next = *liste;
		*liste = push;
	}
	else
	{
		*liste = ft_create_elem(n, suf, lit);
		if (*liste == NULL)
			return (0);
	}
	return (1);
}
