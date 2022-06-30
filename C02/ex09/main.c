/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:23:50 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 20:14:46 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "salut, coMMent tu vas ? 42mots quarante-deux; cinquante+et+UA";
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	write(1, "\n", 1);
	ft_strcapitalize(str);
	write(1, "\n", 1);
	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	check(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			if (i == 0 || check(str[i - 1]))
				str[i] -= (26 + 6);
		if (str[i] >= 'A' && str[i] <= 'Z')
			if (!check(str[i - 1]))
			str[i] += (26 + 6);
		i++;
	}
	return (str);
}
