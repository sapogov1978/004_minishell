/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:32:35 by brattles          #+#    #+#             */
/*   Updated: 2020/11/24 21:15:54 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize != 0 && src_len != 0 && src_len >= dstsize - 1)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	return (src_len);
}
