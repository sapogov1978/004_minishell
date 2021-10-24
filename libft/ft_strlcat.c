/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:32:35 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:36:53 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len > dstsize)
		dst_len = dstsize;
	if (dst_len < dstsize)
	{
		if (src_len < dstsize - dst_len)
		{
			ft_memcpy(dst + dst_len, src, src_len + 1);
		}
		else
		{
			ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (dst_len + src_len);
}
