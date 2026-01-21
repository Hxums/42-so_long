/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:41:26 by hcissoko          #+#    #+#             */
/*   Updated: 2025/11/24 18:37:06 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

• %p The void * pointer argument has to be printed in hexadecimal format.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
*/

/*
printf("%x et  %x\n",12,(unsigned int)-12);
printf("%x et  %x",12,UINT_MAX - 1 + 1);
*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, str + i, 1);
			len++;
		}
		else if (str[i + 1])
			len += ft_print_args(args, str[++i]);
		i++;
	}
	va_end(args);
	return (len);
}
