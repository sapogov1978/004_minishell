/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:53:20 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:12:49 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s) + 1;
	if ((long)(s_len) >= (long)2147483647)
		return (NULL);
	new_str = (char *)malloc(s_len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, s_len);
	return (new_str);
}
