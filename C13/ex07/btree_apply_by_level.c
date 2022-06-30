/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:22:59 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 22:48:28 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	g_level = 0;
int	g_first = 1;

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
	{
		g_level--;
		return ;
	}
	applyf(root->item, g_level, g_first);
	g_level++;
	btree_apply_by_level(root->left, applyf);
	if (root->left)
		g_first = 0;
	g_level++;
	btree_apply_by_level(root->right, applyf);
	g_level--;
}
