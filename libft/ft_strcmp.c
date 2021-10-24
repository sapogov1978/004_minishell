/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <abambi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:53:20 by brattles          #+#    #+#             */
/*   Updated: 2021/10/09 23:21:55 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (*s1)
	{
		if (*s1++ != *s2++)
			return (1);
	}
	return (0);
}
