/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:58:21 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 13:19:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	int	i;

	i = ft_strncmp("Hello", "HeLlo", 3);
	if (i > 0)
		write(1, "more", 4);
	else if (i < 0)
		write(1, "less", 4);
	else
		write(1, "same", 4);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i != n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
