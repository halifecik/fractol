/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:33:51 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 19:01:55 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_rgb(int n)
{
	double	rate;
	int		red;
	int		green;
	int		blue;

	if (n == ITERATION_MAX)
		return (0xF7F5F0);
	rate = (double)n / (double)ITERATION_MAX;
	red = (int)(255 * (1 - rate) * rate * 4);
	green = (int)(64 * (1 - rate) * (1 - rate) * rate * 4);
	blue = (int)(255 * (1 - rate) * (1 - rate) * (1 - rate) * rate * 4);
	return ((red << 16) | (green << 8) | blue);
}
