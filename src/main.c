/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:09 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 05:34:29 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_correct_syntax(void)
{
	ft_printf("----------------------------------------------------------\n\n");
	ft_printf("Types:\n");
	ft_printf("  mandelbrot --- Mandelbrot Set\n");
	ft_printf("  julia      --- Julia Set\n\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia -0.705 0.27023\n");
	ft_printf("  ./fractol julia (optional) [real] [imaginary]\n\n");
	ft_printf("----------------------------------------------------------\n");
}

static int	ft_parse_argument(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		ft_initialize_fractal(fractal, F_MANDELBROT);
		if (argc > 2)
			ft_printf("Error: Mandelbrot does not use extra parameters\n");
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		ft_initialize_fractal(fractal, F_JULIA);
		if (argc >= 4)
		{
			if (!ft_is_number(argv[2]) || !ft_is_number(argv[3]))
			{
				ft_printf("Error: Invalid parameters for Julia set\n");
				return (0);
			}
			fractal->constant.r_num = ft_atod(argv[2]);
			fractal->constant.i_num = ft_atod(argv[3]);
		}
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_memset(&fractal, 0, sizeof(t_fractal));
	if (!ft_parse_argument(argc, argv, &fractal))
	{
		ft_correct_syntax();
		return (1);
	}
	ft_render_fractal(&fractal);
	mlx_key_hook(fractal.window, ft_key_action, &fractal);
	mlx_mouse_hook(fractal.window, ft_mouse_action, &fractal);
	mlx_hook(fractal.window, 17, 0, ft_close_program, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
