/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:51:58 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/23 16:11:51 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest[12] = "Hello ";
	char	src[] = "World";
	int		r;
	int		size = 12;

	r = ft_strlcat(dest, src, size);
	puts(dest);
	printf("Value returned: %d\n", r);
	if (r > size)
		puts("String truncated");
	else
		puts("String was fully copied");
	return (0);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(dest) + ft_strlen(src);
	i = ft_strlen(dest);
	while (*dest)
		dest++;
	while (*src && i < size - 1)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	return (len);
}
