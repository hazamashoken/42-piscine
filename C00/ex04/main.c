/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:25:54 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/08 22:31:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

int main(void)
{
	ft_is_negative(5);
	ft_is_negative(-5);
	return (0);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
		write (1, &"P", 1);
	else 
		write (1, &"N", 1);
}
