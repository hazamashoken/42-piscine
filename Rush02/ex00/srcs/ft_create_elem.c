/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:08:12 by ybayart           #+#    #+#             */
/*   Updated: 2022/06/26 14:57:04 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_dict	*ft_create_elem(int n, int suf, char *literal)
{
	t_dict	*created;

	created = NULL;
	created = malloc(sizeof(t_dict));
	if (created == NULL)
		return (NULL);
	if (created)
	{
		created->nb = n;
		created->suf = suf;
		created->literal = ft_strdup(literal);
		if (created->literal == NULL)
			return (NULL);
		created->next = NULL;
		free(literal);
	}
	return (created);
}
