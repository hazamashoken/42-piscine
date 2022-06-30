/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:21:10 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 22:22:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	countl;
	int	countr;

	if (root)
	{
		countl = btree_level_count(root->left);
		countr = btree_level_count(root->right);
		if (countl > countr)
			return (countl + 1);
		else
			return (countr + 1);
	}
	else
		return (0);
}
