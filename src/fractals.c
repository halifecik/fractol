/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:04 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 04:20:41 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double real, double imag)
{
	double		tmp;
	int			i;
	t_complex	z;
	t_complex	c;

	z.r_num = 0.0;
	z.i_num = 0.0;
	c.r_num = real;
	c.i_num = imag;
	i = 0;
	while (i < ITERATION_MAX)
	{
		if ((z.r_num * z.r_num + z.i_num * z.i_num) > 4.0)
			break ;
		tmp = z.r_num * z.r_num - z.i_num * z.i_num + c.r_num;
		z.i_num = 2.0 * z.r_num * z.i_num + c.i_num;
		z.r_num = tmp;
		i++;
	}
	return (i);
}

int	ft_julia(double real, double imag, t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.r_num = real;
	z.i_num = imag;
	i = 0;
	while (i < ITERATION_MAX)
	{
		if ((z.r_num * z.r_num + z.i_num * z.i_num) > 4.0)
			break ;
		tmp = z.r_num * z.r_num - z.i_num * z.i_num + c.r_num;
		z.i_num = 2.0 * z.r_num * z.i_num + c.i_num;
		z.r_num = tmp;
		i++;
	}
	return (i);
}
