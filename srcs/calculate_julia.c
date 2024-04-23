/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:12 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 20:28:14 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			calculate_julia(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	calculate_julia(t_fractol *fractol)
{
	int		i;
	double	tmp;

	fractol->name = "julia";
	fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
	fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
	i = 0;
	while (++i < fractol->max_iterations)
	{
		tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i
					% 255)));
}
