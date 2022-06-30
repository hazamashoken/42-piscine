/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:34:41 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 19:40:18 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_puthex(char *addr, int size);
void	ft_putaddr(void *addr);
void	ft_print_line(void *addr, int size);
void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	ft_print_memory("Bonjour les aminches\n\n\nc  est fou\ntout\nce qu on peut faire avec\n\n\nprint_memory\n\n\n\nlol.lol\n \0", 92);
	return (0);
}

/*
@brief	... its a function to write char... why are you reading this
@param	char	c	char to be write to stdout
@return	void
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
@brief	write out str in hex
@param	char	*c	pointer to content to by hex out
@param	int		size	size of content to be hex out
@return	void
*/
void	ft_puthex(char *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &"0123456789abcdef"[*addr / 16], 1);
		write(1, &"0123456789abcdef"[*addr % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
		addr++;
	}
}

/*
@brief	write out pointer in hex and pad front with '0' if addr in hex is less
@brief	than 15 chars then write one '0' trailing the addr in hex
@param	void*	addr	pointer to the content
@return	void
*/
void	ft_putaddr(void *addr)
{
	char	addr_c[16];
	long	addr_l;
	int		i;

	addr_l = (long)addr;
	i = 0;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += (55 + 26 + 6);
		addr_l = addr_l / 16;
		i++;
	}
	while (i < 16)
		addr_c[i++] = '0';
	while (--i >= 0)
		ft_putchar(addr_c[i]);
	//write(1, "0", 1);
}

/*
@brief	call ft_puthex on each char and stdout ' ' every 2 chars
@brief	add padding ' ' if printable size is lower than 16
@brief	if char is non-printable stdout '.' 
@param	void*	addr	offseted addr to be print
@param	int		size	size of the content point by addr to be print
@return	void
*/
void	ft_print_line(void *addr, int size)
{
	int		i;
	char	*addr_c;
	int		sp;

	addr_c = (char *)addr;
	i = 0;
	sp = 0;
	while (i < size - 1)
	{
		ft_puthex(addr_c, size);
		i += 16;
		if (size != 16)
			write(1, "    ", 4);
	}
	i = -1;
	while (++i < size)
	{
		if (addr_c[i] >= ' ' && addr_c[i] <= '~')
			ft_putchar(addr_c[i]);
		else
			ft_putchar('.');
	}
}

/*
@brief	call ft_putaddr and ft_print_line and write '\n', offset increase by 16
@brief	every loop till size to be print == 0
@param	void*	addr	pointer to the content
@param	un int	size	size of content to be print
@return	void*			addr of the content
*/
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;
	unsigned int	offset;

	offset = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			len = 16;
			size -= 16;
		}
		else
		{
			len = size;
			size = 0;
		}
		ft_putaddr(addr + offset);
		write(1, ": ", 2);
		ft_print_line(addr + offset, len);
		write(1, "\n", 1);
		offset += 16;
	}
	return (addr);
}
