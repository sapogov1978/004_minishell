/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:49:34 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:34:03 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c_s;
	size_t			i;

	c_s = (unsigned char *)s;
	i = n;
	if (n)
	{
		while (i-- > 0)
		{
			*c_s++ = '\0';
		}
	}
}
