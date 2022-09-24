/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:10:28 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/24 19:10:14 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	rgbnwtn(t_frt *d, double x2, double y2)
{
	if ((y2 - d->cy) * (y2 - d->cy) < d->ra)
		my_mlx_pixel_put(d, d->x, d->y, (0x00FF00));
	if ((x2 - d->cx) * (x2 - d->cx) <= d->ra)
		my_mlx_pixel_put(d, d->x, d->y, (0x0000FF));
	if ((y2 - d->cy) * (y2 - d->cy) + (x2 - d->cx) * (x2 - d->cx) < d->ra)
		my_mlx_pixel_put(d, d->x, d->y, (0XFF0000));
}

void	calcn(t_frt *d)
{
	d->incx = -d->fac + (2 * d->fac / d->ih * d->x);
	d->x2 = d->incx + d->movex;
	d->y2 = d->incy + d->mvy;
	d->i = 0;
}

void	calcn2(t_frt *d)
{
	d->xx = 2 * d->x2 / 3 - (d->x2 * d->x2 - d->y2 * d->y2)
		/ (d->x2 * d->x2 + d->y2 * d->y2) / (d->x2 * d->x2 + d->y2 * d->y2) / 3;
	d->yy = 2 * d->y2 / 3 + 2 * d->x2 * d->y2 / (d->x2 * d->x2 + d->y2 * d->y2)
		/ (d->x2 * d->x2 + d->y2 * d->y2) / 3;
	d->x2 = d->xx * d->inc;
	d->y2 = d->yy * d->inc;
}

void	check_draw(t_frt *d)
{
	if (d->p == 0)
		rgbnwtn(d, d->x2, d->y2);
	if (d->p == 1 || d->p == 2)
	{
		if (d->xx * d->xx + d->yy * d->yy > 10)
			my_mlx_pixel_put(d, d->x, d->y, ((color(d->i, d))));
		if ((d->x - d->cx) * (d->x - d->cx)
			+ (d->y - d->cy) * (d->y - d->cy) < d->ra)
			my_mlx_pixel_put(d, d->x, d->y, (colosr(d->i, 0)));
	}
}

void	ff(t_frt *d)
{
	d->y = 0;
	while (d->y < d->ih)
	{
		d->incy = -d->fac + (2 * (d->fac) / d->ih * (d->y));
		d->x = 0;
		while (d->x < d->iw)
		{
			calcn(d);
			while (d->i < d->maxiterations)
			{
				calcn2(d);
				check_draw(d);
				d->i++;
			}
			d->x++;
		}
		d->y++;
	}
	put2screen(d);
	d->key = 0;
}
