/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:48:16 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/02 17:25:13 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puthexp(unsigned long decimalNumber)
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
			hex[i] = remainder - 10 + 'a';
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
