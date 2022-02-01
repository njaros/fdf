#include "includes/fdf.h"

int	main (int ac, char **av)
{
	void			*mlx;
	void			*win;
	t_data			img;
	t_point_plan	pt;

	(void)ac;
	(void)av;
	pt.x = 800;
	pt.y = 400;
	pt.exist = 0xfd6c9e;
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	win = mlx_new_window(mlx, 1920, 1080, "test");
	trace_trait(pt, 12, 201, &img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
