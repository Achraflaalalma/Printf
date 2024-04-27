/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:41:53 by alaalalm          #+#    #+#             */
/*   Updated: 2023/11/17 18:41:59 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputnbr(unsigned int nb, int *t_char)
{
	if (nb >= 10)
		ft_uputnbr(nb / 10, t_char);
	*t_char += ft_putchar(nb % 10 + '0');
}
