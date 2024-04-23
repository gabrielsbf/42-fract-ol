/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:29:53 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 20:29:54 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initiate_basic_instance(t_fractol *fractol, char *args[], int argc)
{
	float		c1;
	float		c2;

	if (argc == 4)
	{
		c1 = ft_atof(args[2]);
		c2 = ft_atof(args[3]);
	}
	else
	{
		c1 = -0.745429;
		c2 = 0.05;
	}
	start_fractol_att(fractol);
	start_mlx_att(fractol);
	mlx_key_hook(fractol->window, key_handler, fractol);
	mlx_mouse_hook(fractol->window, mouse_handler, fractol);
	mlx_hook(fractol->window, 17, 0L, destroy_fractol, fractol);
	make_fractal(fractol, args[1], c1, c2);
}

int	make_fractal(t_fractol *fractol, char *type, float c1, float c2)
{
	if (ft_strncmp(type, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractol);
	else if (ft_strncmp(type, "julia", 5) == 0)
	{
		fractol->cx = c1;
		fractol->cy = c2;
		draw_julia(fractol);
	}
	else
	{
		print_error_msg();
		destroy_fractol(fractol);
		return (1);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image,
	0 , 0);
	return (0);
}

void	print_error_msg()
{
		ft_putendl_fd("format : ./fractol <fractal set>", 1);
		ft_putendl_fd("avalilable sets : mandelbrot | julia", 1);
		ft_putendl_fd("julia set : ./fractol julia (<julia_c1> <julia_c2>){optional}", 1);
		ft_putendl_fd("recommended values for c1 and c2 : between -1.5 and 1.5",
		1);
}

int	main(int argc, char *argv[])
{
	t_fractol	*fractol;


	if (argc == 2 || argc == 4)
	{
		fractol = malloc(sizeof(t_fractol));
		initiate_basic_instance(fractol, argv, argc);
	}

	if (argc < 2 || argc > 4)
	{
		print_error_msg();
		return (1);
	}
	mlx_loop(fractol->mlx);
	return (0);
}


