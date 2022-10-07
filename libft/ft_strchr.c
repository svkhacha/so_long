/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:00:58 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/11 16:15:20 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*x;
	char	y;

	x = (char *)s;
	y = c;
	i = 0;
	if (!s)
		return (0);
	while (x[i] != '\0' && x[i] != y)
		i++;
	if (x[i] == y)
	{
		return (&x[i]);
	}
	return (0);
}
