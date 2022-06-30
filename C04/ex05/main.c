/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:27:09 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/16 22:06:44 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("%d\n", ft_atoi_base("BAEBDECBBBGB", "ABCDEFG"));
	printf("%d\n", ft_atoi_base(" --++--++--++-012345a6789", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base(" --++--++--++-012345a6789", "01234 56789"));
	printf("%d\n", ft_atoi_base(" --++--++--++-012345a6789", 0));
	printf("%d\n", ft_atoi_base(0, 0));
	printf("%d\n", ft_atoi_base(0, "12345"));
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_validate_base(char *base)
{
	int	i;
	int	k;
	int	len;

	len = ft_strlen(base);
	i = 0;
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] <= ' ' || base[i] > '~')
			|| base[i] == '+' || base[i] == '-')
			return (0);
		k = i + 1;
		while (k < len)
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_basenum(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_neg_space(char *str, int *ptr_i)
{
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	*ptr_i = i;
	return (neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	res;
	int	valid;
	int	len;

	if (base == 0 || str == 0)
		return (0);
	res = 0;
	len = ft_strlen(base);
	i = 0;
	valid = ft_validate_base(base);
	if (!valid)
		return (0);
	neg = ft_neg_space(str, &i);
	while (ft_basenum(str[i], base) != -1)
	{
		res = res * len + ft_basenum(str[i], base);
		i++;
	}
	return (res * neg);
}
