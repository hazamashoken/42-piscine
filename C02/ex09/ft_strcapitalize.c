/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:23:50 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 16:20:29 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
