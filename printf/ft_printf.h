/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcissoko <hcissoko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:46:35 by hcissoko          #+#    #+#             */
/*   Updated: 2025/11/24 18:39:56 by hcissoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
long	ft_recursive_power(long nb, long power);
long	ft_ipower(long n);
int		ft_putnbr_base(unsigned long nbr, char type);
int		ft_putnbr(long nb);
int		ft_print_args(va_list args, char type);
void	ft_putstr(char *str);
# define ABS(Value) (Value < 0 ? -Value : Value)
#endif