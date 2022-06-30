/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:15 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/18 16:49:32 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
@brief	its 	putchar function what more do you expect
@params	char	c	a char, is a char, its a fking char	
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
