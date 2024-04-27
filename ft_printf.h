/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:39:31 by alaalalm          #+#    #+#             */
/*   Updated: 2023/11/17 18:49:31 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putnbr(int nb, int *t_char);
void	ft_uputnbr(unsigned int nb, int *t_char);
int		ft_puthexp(unsigned long decimalNumber);
int		ft_puthex(unsigned int decimalNumber, char specifier);
#endif
