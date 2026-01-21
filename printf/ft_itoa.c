/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:03:49 by hcissoko          #+#    #+#             */
/*   Updated: 2025/11/24 18:41:27 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

long	ft_recursive_power(long nb, long power)
{
	if (power <= 0)
		return (power == 0);
	return (nb * ft_recursive_power(nb, power - 1));
}

long	ft_ipower(long n)
{
	long	power;

	power = 0;
	if (n != 0)
	{
		while (n / ft_recursive_power(10, power))
			power++;
		power--;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	long	power;
	long	negative;
	char	*str;
	long	i;
	long	x;

	i = 0;
	x = n;
	negative = (x < 0);
	if (negative)
		x = -x;
	power = ft_ipower(x);
	str = malloc(sizeof(char) * (power + negative + 2));
	if (!str)
		return (NULL);
	if (negative)
		str[i++] = '-';
	while (-1 < power)
	{
		str[i++] = 48 + (x / ft_recursive_power(10, power));
		x = x % ft_recursive_power(10, power--);
	}
	str[i] = '\0';
	return (str);
}
