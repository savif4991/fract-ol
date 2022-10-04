#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include "./fdf.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"

void	init_p(fdf_t_info *p)
{
	p->mp = NULL;
	p->wp1 = NULL;
	p->x = 0;
	p->y = 0;
	p->x_max = 0;
	p->x_min = 0;
	p->y_max = 0;
	p->y_min = 0;
	p->map_cord = NULL;
	p->map_color = NULL;
	p->map_proj = NULL;
	p->map_size = 0;
}

int	main(int argc, char **argv)
{
	fdf_t_info	p;

	if (argc == 1)
		return (0);
	init_p(&p);
	if (!parse_arg(&p, argv))
		return (err());
	p.mp = mlx_init();
	if (!p.mp)
		return (err());
	p.wp1 = mlx_new_window(p.mp, 1600, 900, "test");
	if (!p.wp1)
		return (err());
	if (!get_projection(&p))
		return (terminate(&p));
	print_int_arr(p);
	sleep(30);
	mlx_destroy_window(p.mp, p.wp1);
	terminate(&p);
	return (0);
}