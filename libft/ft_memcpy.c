/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:53:05 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:33:50 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = -1;
	if (!src && !dest)
		return (NULL);
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
