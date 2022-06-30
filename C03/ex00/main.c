/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:58:21 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 10:53:26 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	int	i;

	i = ft_strcmp("Hello1", "Hello");
	if (i > 0)
		write(1, "more", 4);
	else if (i < 0)
		write(1, "less", 4);
	else
		write(1, "same", 4);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
