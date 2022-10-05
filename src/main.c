/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:57:28 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/05 11:11:09 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	whichfract(t_frt *d)
{
	if (d->which_fract == 1)
		mandel(d);
	else if (d->which_fract == 2)
		julia(d);
	else if (d->which_fract == 3)
		ff(d);
}

void	init_para(t_frt *d)
{
	d->p = 1;
	d->ih = 600;
	d->iw = 600;
	d->movex = 0;
	d->mvy = 0;
	d->key = 0;
	d->fac = 1.00;
	d->zoc = 0.9;
	d->zo = 0.9;
	d->mmx = -0.5;
	d->mouse_x = 0;
	d->mouse_y = 0;
	d->x = 0;
	d->y = 0;
	d->mvy = 0;
}

void	init_mlx(t_frt *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->iw, d->ih, "Fract-ol");
	d->img = mlx_new_image(d->mlx_ptr, d->iw, d->ih);
	d->addr = mlx_get_data_addr(d->img, &d->btxp, &d->line_length, &d->endian);
}

void	input(t_frt *d)
{
	if (d->arg.argc == 1 || d->arg.argc > 4)
		error();
	if (d->arg.argc == 2)
		error();
	if (!ft_strncmp("Mandelbrot", d->arg.argv[1], 11))
		mand_init(d);
	else if (!ft_strncmp("Newton", d->arg.argv[1], 6))
		new_init(d);
	else if (!ft_strncmp("Julia", d->arg.argv[1], 5))
		jul_init(d);
	else
		error();
}	

int	main(int argc, char **argv)
{
	t_frt	d;

	d.arg.argc = argc;
	d.arg.argv = argv;
	ft_printf("%d\n", ft_atoi(d.arg.argv[3]));
	input(&d);
	init_para(&d);
	init_mlx(&d);
	mlx_hook(d.win_ptr, 2, 1L << 0, keypress, &d);
	mlx_hook(d.win_ptr, 06, (1L << 6), pro, &d);
	mlx_hook(d.win_ptr, 17, (1L << 16), ftsclose, &d);
	mlx_mouse_hook(d.win_ptr, mouseclick, &d);
	whichfract(&d);
	mlx_loop(d.mlx_ptr);
}
