#include "fractol.h"

void	ft_error_exit(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}

void	ft_setup_window(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		ft_error_exit("Could not initialize MLX");
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->window)
		ft_error_exit("Could not create window");
}

void	ft_setup_canvas(t_fractal *fractal)
{
	fractal->canvas.image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->canvas.image)
		ft_error_exit("Could not create image");
	fractal->canvas.address = mlx_get_data_addr(fractal->canvas.image,
			&fractal->canvas.bits, &fractal->canvas.line,
			&fractal->canvas.endian);
}

void	ft_initialize_fractal(t_fractal *fractal, int type)
{
	fractal->type = type;
	fractal->zoom = 1.0;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
	if (type == F_JULIA)
	{
		fractal->constant.r_num = -0.705;
		fractal->constant.i_num = 0.27023;
	}
}

void	ft_view_reset(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->x_offset = 0.0;
	fractal->y_offset = 0.0;
	if (fractal->type == F_MANDELBROT)
		fractal->x_offset = -0.5;
	ft_render_fractal(fractal);
}

