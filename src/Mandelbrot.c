/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:34:48 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/05 11:11:18 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	calc(t_frt *d)
{
	if (d->arg.argc == 4)
	{
		if (ft_atoi(d->arg.argv[3]) == 2)
			clac2(d);
		if (ft_atoi(d->arg.argv[3]) == 3)
			clac3(d);
		if (ft_atoi(d->arg.argv[3]) == 5)
			clac5(d);
	}
	else
		errormand();
}

void	calc1(t_frt *d)
{
	d->pr = 1.5 * (d->x - d->iw / 2) / (0.7 * d->zo * d->iw) + d->mmx;
	d->pi = (d->y - d->ih / 2) / (0.5 * d->zo * d->ih) + d->mvy;
	d->newre = 0;
	d->newim = 0;
	d->ore = 0;
	d->oim = 0;
	d->i = 0;
}

int	mandel(t_frt *d)
{
	d->y = 0;
	while (d->y < d->ih)
	{
		d->x = 0;
		while (d->x < d->iw)
		{
			calc1(d);
			while (d->i < (d->maxiterations))
			{
				calc(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 4)
				{
					my_mlx_pixel_put(d, d->x, d->y, (pal_mkg(d->p, d->i, d)));
					break ;
				}
				d->i++;
			}
			d->x++;
		}
		d->y++;
	}
	put2screen(d);
	return (0);
}
