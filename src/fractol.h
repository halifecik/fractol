/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:06 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 05:35:55 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# define ITERATION_MAX 99

# define F_KEY 102
# define R_KEY 114
# define ESC 65307

# define UP_SCROLL 4
# define DOWN_SCROLL 5

# define F_MANDELBROT 0
# define F_JULIA 1

# include "../minilibx-linux/mlx.h"
# include "../utils/utils.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pixel
{
	int			endian;
	int			bits_pp;
	int			line;
	char		*address;
	void		*img;
}				t_pixel;

typedef struct s_complex
{
	double		r_num;
	double		i_num;
}				t_complex;

typedef struct s_fractal
{
	t_pixel		canvas;
	t_complex	constant;
	int			type;
	double		x_offset;
	double		y_offset;
	double		zoom;
	void		*mlx;
	void		*window;
}				t_fractal;

int				ft_close_program(t_fractal *pattern);
void			ft_switch_fractal(t_fractal *pattern);
int				ft_key_action(int key, t_fractal *pattern);
void			ft_view_zoom(t_fractal *pattern, int x, int y, double mult);
int				ft_mouse_action(int button, int x, int y, t_fractal *pattern);

int				ft_color_rgb(int n);

int				ft_mandelbrot(double real, double imag);
int				ft_julia(double real, double imag, t_complex c);

void	ft_error_exit(char *message);
void			ft_view_reset(t_fractal *fractal);
void			ft_window_setup(t_fractal *fractal);
void			ft_canvas_setup(t_fractal *fractal);
void			ft_initialize_fractal(t_fractal *fractal, int type);

void			ft_place_pixel(t_pixel *pixel, int x, int y, int color);
void			ft_coordinate_cmplx(t_fractal *fract, int x, int y,
					t_complex *position);
void			ft_render_fractal(t_fractal *fract);

int				ft_is_number(char *str);
double			ft_atod(const char *str);

#endif