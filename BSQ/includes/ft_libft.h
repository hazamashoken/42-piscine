/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:11:23 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/28 15:51:32 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int b);
void	ft_putstr(char *c);
void	ft_puterr(char *str);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_swap(int *a, int *b);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strstr(char *str, char *to_find);

#endif
