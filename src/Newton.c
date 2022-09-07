/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:10:28 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/26 10:18:37 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void    rgbnwtn(t_frt *d, double x, double y)
{
    if ((y-d->Cy)*(y-d->Cy) < d->Radius)
        my_mlx_pixel_put(d, d->x, d->y, (0x00FF00));
    if ((x-d->Cx)*(x-d->Cx) <= d->Radius)
        my_mlx_pixel_put(d, d->x, d->y, (0x0000FF));
    if ((y-d->Cy)*(y-d->Cy) + (x-d->Cx)*(x-d->Cx) < d->Radius)
        my_mlx_pixel_put(d, d->x, d->y, (0XFF0000));
}

void	ff(t_frt *d)
{   
    double xx = 0;
    double yy = 0;
    d->y = 0;
   
	while (d->y < d->ih)
	{
        double Incy = - d->fac + (2*(d->fac)/d->ih*(d->y));
        
        d->x = 0;
		while (d->x < d->iw)
		{         
            double Incx = - d->fac + (2*d->fac/d->ih*d->x);
            double x = Incx + d->movex;
            double y = Incy + d->mvy;
            d->i = 0;
  
            while (d->i < d->maxiterations)
            {
                
                xx = 2*x/3 - (x*x - y*y)/(x*x + y*y)/(x*x + y*y)/3;
                yy = 2*y/3 + 2*x*y/(x*x + y*y)/(x*x + y*y)/3;
                x = xx * d->inc;
                y = yy * d->inc;
                if (d->p == 0)
                    rgbnwtn(d, x, y);
                if (d->p == 1)
                {
                    if (xx * xx + yy * yy > 10)
                        my_mlx_pixel_put(d, d->x, d->y, ((color(d->i, d))));
                    if ((x-d->Cx)*(x-d->Cx) + (y-d->Cy)*(y-d->Cy) < d->Radius)
                    {
                        my_mlx_pixel_put(d, d->x, d->y, (colosr(d->i,0)));
                    }
                }
                d->i++;
            }   
            d->x++;
        }
        d->y++;
    }
    put2screen(d);
    d->key = 0;
}