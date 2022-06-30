/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:32:01 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 23:10:10 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*str = "Hello world";

	printf("%p\n", str);
	printf("%p\n%s", ft_strstr(str, "wo"), ft_strstr(str, "wo"));
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == to_find[k] && str[i + k] != '\0')
		{
			if (to_find[k + 1] == '\0')
				return (&str[i]);
			k++;
		}
		i++;
	}
	return (0);
}
