/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:05:31 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/26 10:23:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	call(t_frt *d)
{
	d->newre = 1.5 * (d->x - d->iw / 2) / (0.5 * d->zoc * d->iw) + d->movex;
	d->newim = (d->y - d->ih / 2) / (0.5 * d->zoc * d->ih) + d->mvy;
	d->i = 0;
}

void	call1(t_frt *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->cre;
	d->newim = 2 * d->ore * d->oim + d->cim;
}

int	julia(t_frt *d)
{
	d->y = 0;
	while (d->y < d->ih)
	{
		d->x = 0;
		while (d->x < d->iw)
		{
			call(d);
			while (d->i < (d->maxiterations))
			{
				call1(d);
				if ((d->newre * d->newre + d->newim * d->newim) > 5)
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
