/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:00:14 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/12 14:45:40 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	len;
	char	*conc;

	len = ft_strlen(s1) + ft_strlen(s2);
	conc = malloc(sizeof(char) * (len + 1));
	if (!conc)
		return (0);
	i = 0;
	while (*s1)
		conc[i++] = *s1++;
	while (*s2)
		conc[i++] = *s2++;
	conc[i] = 0;
	return (conc);
}
