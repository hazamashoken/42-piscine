/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:23:53 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 15:41:13 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	str1[] = "HELLO";
	char	str2[] = "Hello";
	char	str3[1];

	if (ft_str_is_uppercase(str1))
		write(1, "str1 is upper alpha\n", 13);
	if (ft_str_is_uppercase(str2))
		write(1, "str2 is upper alpha\n", 13);
	if (ft_str_is_uppercase(str3))
		write(1, "str3 is upper alpha\n", 13);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
