/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:49:19 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/21 22:04:56 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len++] != '\0')
		;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*res;

	if (size == 0)
		return (malloc(sizeof(char)));
	len = (size - 1) * (ft_strlen(sep) - 1);
	i = -1;
	while (++i < size)
		len += (ft_strlen(strs[i]) - 1);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	*res = '\0';
	i = -1;
	while (i++ + 1 < size)
	{
		ft_strcat(res, strs[i]);
		if (i + 1 < size)
			ft_strcat(res, sep);
	}
	return (res);
}

int	main(void)
{
	char	**str;

	str = malloc(4 * sizeof(char *));
	str[0] = "12";
	str[1] = "23";
	str[2] = "";
	str[3] = "45";
	printf("%s\n", ft_strjoin(4, str, "+"));
	return (0);
}
