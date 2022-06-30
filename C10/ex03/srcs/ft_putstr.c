/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:53:03 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 14:54:17 by tliangso         ###   ########.fr       */
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

void	ft_putchar_n(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	ft_putstrf(str, 1);
}

void	ft_puterr(char *str)
{
	ft_putstrf(str, 2);
}
