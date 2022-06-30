/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:19:26 by scharuka          #+#    #+#             */
/*   Updated: 2022/06/26 11:22:18 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_rush02.h"

void	ft_list_swap(t_dict *node)
{
	int		num;
	int		suf;
	char	*literal;

	num = node->nb;
	suf = node->suf;
	literal = node->literal;
	node->nb = node->next->nb;
	node->suf = node->next->suf;
	node->literal = node->next->literal;
	node->next->nb = num;
	node->next->suf = suf;
	node->next->literal = literal;
}

int	ft_list_sort(t_dict **begin_list)
{
	t_dict	*i;
	t_dict	*j;

	i = *begin_list;
	while (i != NULL)
	{
		j = *begin_list;
		while (j->next != NULL)
		{
			if (j->nb < j->next->nb)
				ft_list_swap(j);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
