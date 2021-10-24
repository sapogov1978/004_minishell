/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:13:39 by abambi            #+#    #+#             */
/*   Updated: 2021/10/17 22:03:56 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char const *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (n_words == 0 || s[i - 1] == c))
			++n_words;
		i++;
	}
	return (n_words);
}

static int	ft_len_word(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static int	ft_putstr(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
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

char	**ft_split(char const *arr, char c)
{
	int		n_words;
	int		len_word;
	char	**arr_ptrs;
	int		j;

	if (!arr)
		return (NULL);
	j = 0;
	n_words = ft_n_words(arr, c);
	arr_ptrs = malloc((n_words + 1) * sizeof(char *));
	if (!arr_ptrs)
		return (NULL);
	while (j < n_words)
	{
		len_word = ft_len_word(arr, c);
		while (*arr == c)
			arr++;
		arr_ptrs[j] = malloc((len_word + 1) * sizeof(char));
		if (!arr_ptrs[j])
			return (ft_free_malloc(&arr_ptrs[j], j));
		arr = arr + ft_putstr(arr_ptrs[j], arr, len_word + 1);
		j++;
	}
	arr_ptrs[j] = NULL;
	return (arr_ptrs);
}
