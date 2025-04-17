/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:00 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:01 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../utils/utils.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 1000
# define WIDTH 1000
# define ITERATION_MAX 50

# define F_JULIA 1
# define F_MANDELBROT 0

# define F_KEY 102
# define R_KEY 114
# define ESC 65307

# define UP_SCROLL 4
# define DOWN_SCROLL 5

typedef struct s_complex
{
	double		r_num;
	double		i_num;
}				t_complex;

typedef struct s_pixel
{
	int			bits;
	int			line;
	int			endian;
	char		*address;
	void		*image;
}				t_pixel;

typedef struct s_fractal
{
	t_complex	constant;
	t_pixel		canvas;
	int			type;
	double		zoom;
	double		x_offset;
	double		y_offset;
	void		*mlx;
	void		*window;
}				t_fractal;

int				ft_action_key(int key, t_fractal *fractal);
int				ft_action_mouse(int button, int x, int y, t_fractal *fractal);
void			ft_switch_pattern(t_fractal *fractal);
void			ft_view_zoom(t_fractal *fractal, int x, int y, double rate);
int				ft_close_program(t_fractal *fractal);

int				ft_color_rgb(int n);

int				ft_mandelbrot(double real, double imag);
int				ft_julia(double real, double imag, t_complex c);

void			ft_error_exit(char *message);
void			ft_setup_window(t_fractal *fractal);
void			ft_setup_canvas(t_fractal *fractal);
void			ft_initialize_fractal(t_fractal *fractal, int type);
void			ft_view_reset(t_fractal *fractal);

void			ft_place_pixel(t_pixel *pixel, int x, int y, int color);
void			ft_complex_coordinates(t_fractal *fract, int x, int y,
					t_complex *position);
void			ft_render_fractal(t_fractal *fract);

int				ft_is_number(char *str);
double			ft_atod(const char *str);

#endif
