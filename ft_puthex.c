/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:34:23 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/02 18:05:06 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_x(char specifier, char *hex, int *remainder)
{
	if (specifier == 'x')
		*hex = *remainder - 10 + 'a';
	else if (specifier == 'X')
		*hex = *remainder - 10 + 'A';
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int decimalNumber, char specifier)
{
	char	hex[17];
	int		i;
	int		remainder;
	int		hexlen;

	i = 0;
	while (decimalNumber > 0)
	{
		remainder = decimalNumber % 16;
		if (remainder < 10)
			hex[i] = remainder + '0';
		else
			check_x(specifier, (hex + i), &remainder);
		i++;
		decimalNumber /= 16;
	}
	hex[i] = '\0';
	hexlen = i - 1;
	while (hexlen >= 0)
	{
		ft_putchar(hex[hexlen]);
		hexlen--;
	}
	return (ft_strlen(hex));
}
