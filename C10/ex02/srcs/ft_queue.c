/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:26:17 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:29:27 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_push_queue(t_queue *f, char *bytes, int size)
{
	int	i;

	if (f->size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		f->data[f->pos] = bytes[i];
		f->pos++;
		if (f->pos == f->size)
			f->pos = 0;
		f->len++;
		if (f->len > f->size)
			f->len = f->size;
		i++;
	}
}

int	ft_create_queue(t_queue *f, int size)
{
	if (size > 0)
	{
		f->data = malloc(size);
		if (f->data == NULL)
			return (0);
	}
	else
	{
		f->data = NULL;
	}
	f->size = size;
	f->len = 0;
	f->pos = 0;
	return (1);
}

void	ft_free_queue(t_queue *f)
{
	if (f->data != NULL)
		free(f->data);
	f->data = NULL;
	f->size = 0;
	f->len = 0;
	f->pos = 0;
}

void	ft_print_queue(t_queue *f)
{
	if (f->len != 0)
	{
		write(1, &(f->data[f->pos]), f->len - f->pos);
		write(1, &(f->data[0]), f->pos);
	}
}
