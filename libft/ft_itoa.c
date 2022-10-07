/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:42:15 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/13 15:16:23 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = ft_numlen(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len] = num % 10 + '0';
		len--;
		num = num / 10;
	}
	return (str);
}
