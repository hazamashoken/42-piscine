/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:54:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 14:51:22 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <libgen.h>

typedef struct s_hexqueue
{
	char	buffer[16];
	char	p_buffer[16];
	int		count;
	int		c_type;
	int		len;
	int		match;
	int		first;
}	t_hexqueue;

void	hq_new(t_hexqueue *hq, int is_c_type);
void	hq_add(t_hexqueue *hq, char b);
void	hq_flush(t_hexqueue *hq);
void	hq_print(t_hexqueue *hq);
void	hq_print_final(t_hexqueue *hq);
void	ft_putchar(char c);
void	ft_putchar_n(char c, int n);
void	ft_putstr(char *str);
void	ft_puterr(char *str);
int		char_to_byte(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strnum(char *str);
void	ft_puthex(int nb, int pad);
void	ft_print_hex(char *bytes, int size);
void	ft_print_hex_c(char *bytes, int size);
void	ft_print_hex_text(char *bytes, int size);

#endif
