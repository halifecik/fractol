/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:11 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 04:21:20 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_place_pixel(t_pixel *pixel, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		pxl = pixel->address + (y * pixel->line + x * (pixel->bits_pp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	ft_coordinate_cmplx(t_fractal *fract, int x, int y, t_complex *position)
{
	position->r_num = (4.0 * ((double)x / WIDTH - 0.5)) * fract->zoom
		+ fract->x_offset;
	position->i_num = (4.0 * ((double)y / HEIGHT - 0.5)) * fract->zoom
		+ fract->y_offset;
}

void	ft_render_fractal(t_fractal *fract)
{
	int			i;
	int			x;
	int			y;
	t_complex	position;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_coordinate_cmplx(fract, x, y, &position);
			if (fract->type == F_MANDELBROT)
				i = ft_mandelbrot(position.r_num, position.i_num);
			else
				i = ft_julia(position.r_num, position.i_num, fract->constant);
			ft_place_pixel(&fract->canvas, x, y, ft_color_rgb(i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->canvas.img, 0, 0);
}
