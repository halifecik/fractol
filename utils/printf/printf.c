/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:20:02 by hademirc          #+#    #+#             */
/*   Updated: 2024/12/24 17:30:05 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_flag_check(char c, va_list a)
{
	if (c == 'c')
		return (ft_putchar(va_arg(a, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(a, char *)));
	else if (c == 'p')
		return (ft_px_printer(va_arg(a, unsigned long),
				"0123456789abcdef", 1));
	else if (c == 'd' || c == 'i')
		return (ft_id_printer(va_arg(a, int)));
	else if (c == 'u')
		return (ft_u_printer(va_arg(a, unsigned int)));
	else if (c == 'x')
		return (ft_px_printer(va_arg(a, unsigned int),
				"0123456789abcdef", 0));
	else if (c == 'X')
		return (ft_px_printer(va_arg(a, unsigned int),
				"0123456789ABCDEF", 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	a;
	int		i;
	int		len;

	va_start(a, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ')
				i++;
			len += ft_flag_check(str[i], a);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}
