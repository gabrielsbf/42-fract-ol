/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:35:21 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 13:35:24 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_adr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractol;

# define SIZE 900
# define ESC 65307
# define ARR_LEFT 65361
# define ARR_UP 65362
# define ARR_RIGHT 65363
# define ARR_DOWN 65364
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

void	start_fractol_att(t_fractol *fractol);
void	start_mlx_att(t_fractol *fractol);
void	initiate_basic_instance(t_fractol *fractol, char *args[], int argc);
int		destroy_fractol(t_fractol *fractol);
void	calculate_mandelbrot(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
void	put_color_to_pixel(t_fractol *fractol, int x, int y, int color);
void	draw_julia(t_fractol *fractol);
int		make_fractal(t_fractol *fractol, char *type, float c1, float c2);
void	calculate_julia(t_fractol *fractol);
int		key_handler(int key_code, t_fractol *fractol);
int		mouse_handler(int mouse_code, int x, int y, t_fractol *fractol);
void	print_error_msg();
void	zoom(t_fractol *fractol, int x, int y, int zoom);
#endif
