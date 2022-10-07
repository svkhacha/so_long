/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:55:09 by svkhacha          #+#    #+#             */
/*   Updated: 2022/08/11 16:14:25 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = -n;
	}
	else
	{
		number = n;
	}
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
	else
		ft_putchar_fd(number + 48, fd);
}
