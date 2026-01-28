/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:39:24 by hcissoko          #+#    #+#             */
/*   Updated: 2026/01/28 20:58:57 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

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
	x = nb;
	if (x < 0)
		x = -x;
	if (x / 10 > 0)
	{
		len += ft_putnbr(x / 10);
	}
	c = (x % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
