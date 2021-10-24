/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:39:39 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 23:01:26 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoin;
	int				i;
	int				j;
	int				len[2];

	i = 0;
	j = 0;
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (!strjoin)
		return (NULL);
	while (s1 && i < len[0])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2 && j < len[1])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len[0] + len[1]] = '\0';
	return (strjoin);
}

char	*ft_strjoinf(char **s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;
	char	*s1_copy;

	if (!*s1 || !s2)
		return (NULL);
	s1_copy = *s1;
	len_s1 = 0;
	len_s2 = 0;
	while (s1_copy[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ptr == NULL)
		freex(s1);
	if (ptr == NULL)
		return (NULL);
	while (*s1_copy)
		*ptr++ = *s1_copy++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr - len_s1 - len_s2 - freex(s1));
}

int	freex(char **s)
{
	if (s)
	{
		free(*s);
		*s = 0x0;
	}
	return (0);
}
