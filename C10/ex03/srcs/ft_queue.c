/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:50:22 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 14:50:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	hq_new(t_hexqueue *hq, int is_c_type)
{
	hq->count = 0;
	hq->c_type = is_c_type;
	hq->len = 0;
	hq->match = 0;
	hq->first = 1;
}

void	hq_add(t_hexqueue *hq, char b)
{
	hq->buffer[hq->len] = b;
	hq->len++;
	if (hq->len == 16)
	{
		hq_flush(hq);
	}
}

void	hq_flush(t_hexqueue *hq)
{
	int	diff;
	int	i;

	i = 0;
	diff = 0;
	while (i < hq->len)
	{
		if (!hq->first && hq->p_buffer[i] != hq->buffer[i])
			diff = 1;
		hq->p_buffer[i] = hq->buffer[i];
		i++;
	}
	if (!diff && hq->match == 0 && !hq->first && hq->len != 0)
	{
		hq->match = 1;
		ft_putstr("*\n");
	}
	else if (diff || hq->first)
	{
		hq->match = 0;
		hq_print(hq);
	}
	hq->first = 0;
	hq->count += hq->len;
	hq->len = 0;
}

void	hq_print(t_hexqueue *hq)
{
	if (hq->count != 0 || hq->len != 0)
	{
		if (!hq->c_type)
		{
			ft_puthex(hq->count, 7);
			ft_print_hex(hq->buffer, hq->len);
		}
		else
		{
			ft_puthex(hq->count, 8);
			ft_print_hex_c(hq->buffer, hq->len);
			ft_putchar_n(' ', (16 - hq->len) * 3 + 2);
			if (hq->len <= 8)
				ft_putchar(' ');
			ft_print_hex_text(hq->buffer, hq->len);
		}
		ft_putchar('\n');
	}
}

void	hq_print_final(t_hexqueue *hq)
{
	if (hq->count != 0)
	{
		if (!hq->c_type)
			ft_puthex(hq->count, 7);
		else
			ft_puthex(hq->count, 8);
		ft_putchar('\n');
	}
}
