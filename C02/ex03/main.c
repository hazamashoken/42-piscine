/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:23:53 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/14 23:02:41 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	str1[] = "12345";
	char	str2[] = "1234AB5";
	char	str3[1];

	if (ft_str_is_numeric(str1))
		write(1, "str1 is numeric", 13);
	if (ft_str_is_numeric(str2))
		write(1, "str2 is numeric", 13);
	if (ft_str_is_numeric(str3))
		write(1, "str3 is numeric", 13);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
