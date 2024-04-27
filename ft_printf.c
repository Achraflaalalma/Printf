/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:33:51 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/08 10:01:36 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_specifier2(va_list args, int *t_char, char specifier)
{
	void			*ptr;
	unsigned int	value;

	if (specifier == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			*t_char += ft_putstr("0x0");
		else
		{
			*t_char += ft_putstr("0x");
			*t_char += ft_puthexp((unsigned long)ptr);
		}
	}
	else if (specifier == 'x' || specifier == 'X')
	{
		value = va_arg(args, unsigned int);
		if (value == 0)
			*t_char += ft_putchar('0');
		*t_char += ft_puthex(value, specifier);
	}
	else
		*t_char += ft_putchar(specifier);
}

static void	format_specifier1(va_list args, int *t_char, char specifier)
{
	if (specifier == 'c')
		*t_char += ft_putchar(va_arg(args, int));
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), t_char);
	else if (specifier == 'u')
		ft_uputnbr(va_arg(args, unsigned int), t_char);
	else if (specifier == '%')
		*t_char += ft_putchar('%');
	else if (specifier == 's')
		*t_char += ft_putstr(va_arg(args, char *));
	else
		format_specifier2(args, t_char, specifier);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		t_char;
	int		i;

	va_start(args, format);
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	t_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				format_specifier1(args, &t_char, format[i]);
			else if (format[i] == '\0')
				return (t_char);
		}
		else
			t_char += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (t_char);
}
