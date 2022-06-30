/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:09:54 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 18:50:37 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
void			test(int size);

int	main(void)
{
	test(19);
	test(10);
	test(5);
	test(0);
	return (0);
}

void	test(int size)
{
	char	string[] = "Hello world, we are born 2 code.";
	char	buffer[19];
	int		r;

	r = ft_strlcpy(buffer, string, size);
	printf("%s, src len: %d\n", buffer, r);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/*
@brief	copy char from src to dest for whithin the input size
@param	char*	dest	pointer to first char of dest
@param	char*	src		pointer to first char of src
@param	un int	size	size of src to be cpy to dest
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(src);
	i = 0;
	if (size)
	{
		while (*src && i < size - 1)
		{
			*dest = *src;
			dest++;
			src++;
			i++;
		}
		*dest = '\0';
	}
	return (n);
}
