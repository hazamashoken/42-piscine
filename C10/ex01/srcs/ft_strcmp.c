/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:23:26 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:12:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	char_to_byte(char c)
{
	int	u;

	u = c;
	if (u < 0)
	{
		u = u + 256;
	}
	return (u);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (char_to_byte(*s1) - char_to_byte(*s2));
}

int	ft_strnum(char *str)
{
	if (str == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
