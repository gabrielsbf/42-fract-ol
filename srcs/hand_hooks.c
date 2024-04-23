/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:22 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 20:28:58 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_handler(int key_code, t_fractol *fractol)
{
	if (key_code == ESC)
	{
		destroy_fractol(fractol);
		return (0);
	}
	else if (key_code == ARR_LEFT)
		fractol->offset_x -= 42 / fractol->zoom;
	else if (key_code == ARR_RIGHT)
		fractol->offset_x += 42 / fractol->zoom;
	else if (key_code == ARR_UP)
		fractol->offset_y -= 42 / fractol->zoom;
	else if (key_code == ARR_DOWN)
		fractol->offset_y += 42 / fractol->zoom;
	make_fractal(fractol, fractol->name, fractol->cx, fractol->cy);
	return (0);
}

int	mouse_handler(int mouse_code, int x, int y, t_fractol *fractol)
{
	if (mouse_code == MOUSE_SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse_code == MOUSE_SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	make_fractal(fractol, fractol->name, fractol->cx, fractol->cy);
	return (0);
}
