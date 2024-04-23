/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:29:44 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 20:29:45 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	start_fractol_att(t_fractol *fractol)
{
	fractol->color = 0x0F1B38;
	fractol->zoom = 200;
	fractol->x = 0;
	fractol->y = 0;
	fractol->offset_x = -1.80;
	fractol->offset_y = -1.80;
	fractol->max_iterations = 42;
}

void	start_mlx_att(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "fractol");
	fractol->image = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->img_adr = mlx_get_data_addr(fractol->image,
										&fractol->bits_per_pixel,
										&fractol->size_line,
										&fractol->endian);
}

int	destroy_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	ft_printf("destroy was called\n");
	exit(1);
	return(0);
}
