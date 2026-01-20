/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:39:24 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/19 22:23:22 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr(long nb)
{
	long	x;
	int		len;
	char	c;

	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		len++;
	}
	x = ABS(nb);
	if (x / 10 > 0)
	{
		len += ft_putnbr(x / 10);
	}
	c = (x % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
