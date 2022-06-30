/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:53:03 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:04:01 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstrf(char *str, int fd)
{
	if (str == 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}

void	ft_print_file(int fd)
{
	char	c;

	while (read(fd, &c, 1))
		write(1, &c, 1);
}
