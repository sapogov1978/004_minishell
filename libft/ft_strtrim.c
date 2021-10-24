/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:20:24 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:10:56 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!set)
		return ((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[size]) && size > 0)
		size--;
	dest = ft_substr(s1, i, size + 1 - i);
	return (dest);
}
