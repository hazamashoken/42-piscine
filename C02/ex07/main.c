/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:59:33 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 15:43:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strupcase(char *str);
void	ft_putchar(char c);


int	main(void)
{
	char	str[] = "Hello123";
	int		i;

	i = 0;
	ft_strupcase(str);
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= (26 + 6);
		i++;
	}
	return (str);
}
