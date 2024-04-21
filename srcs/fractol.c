#include "../includes/fractol.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	(void)mlx_win;
	(void)img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Changed");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_destroy_window()

	mlx_loop(mlx);
}
