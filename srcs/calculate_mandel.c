/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mandel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:17 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 20:28:19 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			calculate_mandelbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	calculate_mandelbrot(t_fractol *fractol)
{
	int		i;
	double	x_temp;

	fractol->name = "mandelbrot";
	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++i < fractol->max_iterations)
	{
		x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_temp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color
				* i));
}
