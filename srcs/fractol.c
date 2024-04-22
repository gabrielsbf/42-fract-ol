#include "../includes/fractol.h"

int	key_handler(int var_k)

int main()
{
	t_img_inst *win_inst;

	win_inst->mlx = mlx_init();
	win_inst->window = mlx_new_window(win_inst->mlx, 1920, 1080, "fractol");
	mlx_key_hook(win_inst->window, );
	mlx_loop(mlx);
}
