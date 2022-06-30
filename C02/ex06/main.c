/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:23:53 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/14 23:03:56 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hel\nlo";
	char	str3[1];

	if (ft_str_is_printable(str1))
		write(1, "str1 is printable\n", 18);
	if (ft_str_is_printable(str2))
		write(1, "str2 is printable\n", 18);
	if (ft_str_is_printable(str3))
		write(1, "str3 is printable\n", 18);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
			return (0);
		str++;
	}
	return (1);
}
