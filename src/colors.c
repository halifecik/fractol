#include "fractol.h"

int	ft_color_rgb(int n)
{
	double	rate;
	int		red;
	int		green;
	int		blue;

	if (n == ITERATION_MAX)
		return (0x000000);
	rate = (double)n / (double)ITERATION_MAX;
	red = (int)(9 * rate * rate * rate * (1 - rate) * 255);
	green = (int)(13 * rate * rate * (1 - rate) * (1 - rate) * 255);
	blue = (int)(16 * rate * (1 - rate) * (1 - rate) * (1 - rate) * 255);
	return ((red << 16) | (green << 8) | blue);
}