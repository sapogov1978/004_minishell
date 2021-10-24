/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 02:06:34 by brattles          #+#    #+#             */
/*   Updated: 2021/10/17 22:48:13 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	int_len;

	int_len = 0;
	if (n == 0)
		int_len = 1;
	if (n < 0)
		int_len++;
	while (n)
	{
		n = n / 10;
		int_len += 1;
	}
	return (int_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	int_len = ft_int_len(n);
	str = (char *)malloc(sizeof(char) * (int_len + 1));
	if (!str)
		return (NULL);
	str[int_len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (i < int_len--)
	{
		str[int_len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
