/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:18:35 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:13:16 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size > 2147483647)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr)
	{
		ft_bzero(ptr, nmemb * size);
		return (ptr);
	}
	return (NULL);
}
