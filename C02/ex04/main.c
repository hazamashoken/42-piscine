/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:23:53 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 14:39:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "Hello";
	char	str3[1];

	if (ft_str_is_lowercase(str1))
		write(1, "str1 is lower alpha\n", 13);
	if (ft_str_is_lowercase(str2))
		write(1, "str2 is lower alpha\n", 13);
	if (ft_str_is_lowercase(str3))
		write(1, "str3 is lower alpha\n", 13);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{	
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}
