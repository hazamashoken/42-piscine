/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destory_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:45:34 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 01:46:37 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_header.h"

/*
@brief		free the memory allocated to tab
@params	char** 	tab	board/table chair 
@params	int		size	size of board
*/
void	ft_destroy_tab(char **tab, int size)
{
	while (size--)
		free(tab[size]);
	free(tab);
}
