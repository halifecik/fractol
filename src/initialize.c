#include "fractol.h"

static void	ft_error_exit(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}

void	ft_view_reset(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
	if (fractal->type == F_MANDELBROT)
		fractal->x_offset = -0.5;
	render_fractal(fractal);
}

void	ft_window_setup(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		ft_error_exit("Couldn't initialize MLX.");
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->window)
		ft_error_exit("Couldn't create window.");
}

void	ft_canvas_setup(t_fractal *fractal)
{
	fractal->canvas.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->canvas.img)
		ft_error_exit("Could not create image");
	fractal->canvas.address = mlx_get_data_addr(fractal->canvas.img,
			&fractal->canvas.bits_pp, &fractal->canvas.line,
			&fractal->canvas.endian);
}

void	ft_initialize_fractal(t_fractal *fractal, int type)
{
	fractal->type = type;
	fractal->max = ITERATION_MAX;
	fractal->zoom = 1.0;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
	if (type == F_JULIA)
	{
		fractal->constant.r_num = -0.7;
		fractal->constant.i_num = 0.27015;
	}
	ft_window_setup(fractal);
	ft_canvas_setup(fractal);
	ft_view_reset(fractal);
}