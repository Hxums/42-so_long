/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:38:22 by hcissoko          #+#    #+#             */
/*   Updated: 2025/11/24 18:35:52 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_p(unsigned long nb)
{
	if (nb == 0)
		return (ft_print_s("(nil)"));
	ft_putstr("0x");
	return (2 + ft_putnbr_base(nb, 'p'));
}

int	ft_print_args(va_list args, char type)
{
	if (type == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (type == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (type == '%')
		return (ft_print_c('%'));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_print_p(va_arg(args, unsigned long)));
	return (0);
}
