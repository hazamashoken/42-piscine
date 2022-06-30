/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:06:23 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 13:08:46 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	main(void)
{
	ft_putstr("Hello");
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}
