/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:50:32 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/27 14:23:50 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

/*
@brief	check if the char match the char in seperator array
@params	char	c			char from string to be check
@params	char*	charset		seperator set
@return	int					1 or 0 depend on if c is in charset
*/
int	ft_check_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/*
@brief	call ft_check_seperator to check how many string need to be seperate
@params	char*	str		inputed string
@params char*	charset	seperator char array
@return int				the number of strings after spilt
*/
int	ft_count_strings(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_check_separator(str[i], charset))
			i++;
	}
	return (count);
}

/*
@brief	find the length of string till next seperator
@params	char*	str 	poitner to current pos in string
@params	char*	charset	array of seperator
@return int				length of word seperated
*/
int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_check_separator(str[i], charset))
		i++;
	return (i);
}

/*
@brief	assign the word sperated by charset in to array and return it
@params	char*	str		inputed string
@params	char*	charset	the seperator string
@return char*			string of seperated word
*/
char	*ft_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
@brief	take in a string, seperate it by char in charset and 
@brief	return as array in array
@params	char*	str		inputed	string
@params	char*	charset	string of seperator
@return char**			array of array of seperated words
*/
char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *)
			* (ft_count_strings(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && ft_check_separator(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !ft_check_separator(*str, charset))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
