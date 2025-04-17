/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:01 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 04:06:30 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_switch_fractal(t_fractal *pattern)
{
	pattern->type = (pattern->type + 1) % 2;
	if (pattern->type == F_JULIA)
	{
		pattern->constant.r_num = -0.7;
		pattern->constant.i_num = 0.27015;
	}
	ft_view_reset(pattern);
}

int	ft_mouse_action(int button, int x, int y, t_fractal *pattern)
{
	if (button == UP_SCROLL)
		ft_view_zoom(pattern, x, y, 1.2);
	else if (button == DOWN_SCROLL)
		ft_view_zoom(pattern, x, y, 0.75);
	return (0);
}

int	ft_key_action(int key, t_fractal *pattern)
{
	if (key == ESC)
		ft_close_program(pattern);
	else if (key == F_KEY)
		ft_switch_fractal(pattern);
	else if (key == R_KEY)
		ft_view_reset(pattern);
	return (0);
}

void	ft_view_zoom(t_fractal *pattern, int x, int y, double mult)
{
	double	previous;

	(void)x;
	(void)y;
	previous = pattern->zoom;
	pattern->zoom *= mult;
	pattern->x_offset = pattern->x_offset * previous / pattern->zoom;
	pattern->y_offset = pattern->y_offset * previous / pattern->zoom;
	ft_render_fractal(pattern);
}

int	ft_close_program(t_fractal *pattern)
{
	mlx_destroy_image(pattern->mlx, pattern->canvas.img);
	mlx_destroy_window(pattern->mlx, pattern->window);
	mlx_destroy_display(pattern->mlx);
	free(pattern->mlx);
	exit(0);
	return (0);
}
