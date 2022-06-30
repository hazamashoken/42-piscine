/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:22:46 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 18:58:00 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

int	main(void)
{
	char	dest[10] = "World";
	char	src[] = "Hello";
	char	*deset_ptr = ft_strcpy(dest, src);

	printf("     src: %s\n", src);
	printf("    dest: %s\n", dest);
	printf("dest_ptr: %s\n", deset_ptr);
	printf("    dest: %p\n", dest);
	printf("dest_ptr: %p\n", dest);
}
