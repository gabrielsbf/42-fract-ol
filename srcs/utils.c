#include "../includes/fractol.h"

void	put_color_to_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	*buffer;

	buffer = fractol->img_adr;
	buffer[(y * fractol->size_line / 4) + x] = color;
}

void	zoom(t_fractol *fractol, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom * zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom * zoom_level));
		fractol->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom / zoom_level));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom / zoom_level));
		fractol->zoom /= zoom_level;
	}
	else
		return ;
}
