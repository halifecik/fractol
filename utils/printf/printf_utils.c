/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:25:55 by hademirc          #+#    #+#             */
/*   Updated: 2024/12/14 15:34:58 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_id_printer(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		len += ft_id_printer(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}

int	ft_px_printer(unsigned long nb, char *base, int flag)
{
	int	len;

	len = 0;
	if (flag == 1)
	{
		if (nb == 0)
		{
			len += ft_putstr("(nil)");
			return (len);
		}
		len += ft_putstr("0x");
	}
	if (nb >= 16)
		len += ft_px_printer(nb / 16, base, 0);
	len += write(1, &base[nb % 16], 1);
	return (len);
}

int	ft_u_printer(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
		len += ft_u_printer(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
