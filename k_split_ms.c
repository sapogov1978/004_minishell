/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_split_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:13:39 by abambi            #+#    #+#             */
/*   Updated: 2021/10/19 21:27:01 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_n_words(char *s, char c)
{
	int		i;
	int		n_words;
	char	flag_begin;

	i = 0;
	n_words = 0;
	while (s[i] != '\0')
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		if (s[i] != c && (n_words == 0 || s[i - 1] == c))
			++n_words;
		i++;
	}
	return (n_words);
}

static int	ft_len_word(char *s, char c)
{
	char	flag_begin;
	int		i;

	if (*s == c)
		s++;
	i = 0;
	while (s[i] && s[i] != c)
	{
		flag_begin = ft_smart_detect_char(&s[i], i);
		if (flag_begin != 0)
		{
			while (s[++i])
			{
				if (ft_smart_detect_char(&s[i], i) == flag_begin)
					break ;
			}
		}
		i++;
	}
	return (i);
}

static int	ft_putstr(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (i);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

static char	**ft_free_malloc(char **arr_ptrs, int j)
{
	while (j >= 0)
		free(arr_ptrs[j--]);
	free(arr_ptrs);
	return (NULL);
}

char	**ft_split_ms(char *arr, char c)
{
	int		n_words;
	char	**arr_ptrs;
	int		i;

	check_start_errors(arr);
	check_split_errors(arr, c);
	n_words = ft_n_words(arr, c);
	arr_ptrs = malloc(sizeof(char *) * (n_words + 1));
	if (arr_ptrs == NULL)
		return (NULL);
	i = -1;
	while (++i < n_words)
	{
		if (*arr == c)
			arr++;
		arr_ptrs[i] = malloc(sizeof(char) * (ft_len_word(arr, c) + 1));
		if (arr_ptrs[i] == NULL)
			return (ft_free_malloc(&arr_ptrs[i], i));
		arr += ft_putstr(arr_ptrs[i], arr, ft_len_word(arr, c) + 1);
	}
	arr_ptrs[i] = NULL;
	return (arr_ptrs);
}
