/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:09:54 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 16:05:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
