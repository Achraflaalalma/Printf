/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:54:35 by alaalalm          #+#    #+#             */
/*   Updated: 2023/11/17 12:51:05 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *t_char)
{
	if (nb == -2147483648)
	{
		*t_char += 11;
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		*t_char += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, t_char);
	*t_char += ft_putchar(nb % 10 + '0');
}
