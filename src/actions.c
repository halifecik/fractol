#include "fractol.h"

int	ft_action_key(int key, t_fractal *fractal)
{
	if (key == ESC)
		ft_close_program(fractal);
	else if (key == F_KEY)
		ft_switch_pattern(fractal);
	else if (key == R_KEY)
		ft_view_reset(fractal);
	return (0);
}

int	ft_action_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == UP_SCROLL)
		ft_view_zoom(fractal, x, y, 1.1);
	else if (button == DOWN_SCROLL)
		ft_view_zoom(fractal, x, y, 0.9);
	return (0);
}

void	ft_switch_pattern(t_fractal *fractal)
{
	fractal->type = (fractal->type + 1) % 2;
	if (fractal->type == F_JULIA)
	{
		fractal->constant.r_num = -0.7;
		fractal->constant.i_num = 0.27015;
	}
	ft_view_reset(fractal);
}

void	ft_view_zoom(t_fractal *fractal, int x, int y, double rate)
{
	double	old;

	(void)x;
	(void)y;
	old = fractal->zoom;
	fractal->zoom *= rate;
	fractal->x_offset = fractal->x_offset * old / fractal->zoom;
	fractal->y_offset = fractal->y_offset * old / fractal->zoom;
	ft_render_fractal(fractal);
}

int	ft_close_program(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->canvas.image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}
