/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:11:31 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 22:20:09 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_strcmp(void	*s1, void *s2)
{
	return ((char *)s1 - (char *)s2);
}

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*elem;

	if (root)
	{
		elem = btree_search_item(root->left, data_ref, cmpf);
		if (elem)
			return (elem);
		if (!cmpf(root->item, data_ref))
			return (root->item);
		elem = btree_search_item(root->right, data_ref, cmpf);
		if (elem)
			return (elem);
	}
	return (0);
}
