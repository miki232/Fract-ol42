/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:36:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/23 19:15:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	my_mlx_pixel_put(t_frt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->btxp / 8));
	*(unsigned int *)dst = color;
}

int	clear(t_frt *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, d->iw, d->ih);
	d->addr = mlx_get_data_addr(d->img, &d->btxp, &d->line_length, &d->endian);
	return (0);
}

void	put2screen(t_frt *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

int	color1(int inter, t_frt *data)
{
	if (inter == ((int)data->maxiterations - 20))
		return (0x00b8b2);
	else if (inter == ((int)data->maxiterations - 19))
		return (0x00b89e);
	else if (inter == ((int)data->maxiterations - 18))
		return (0x76b874);
	else if (inter == ((int)data->maxiterations - 17))
		return (0xa0b85e);
	else if (inter == ((int)data->maxiterations - 16))
		return (0xc6b644);
	else if (inter == ((int)data->maxiterations - 15))
		return (0xfeb500);
	else if (inter == ((int)data->maxiterations - 14))
		return (0xff8c00);
	else if (inter == ((int)data->maxiterations - 13))
		return (0xfb7700);
	else if (inter == ((int)data->maxiterations - 12))
		return (0xec4e02);
	else if (inter == ((int)data->maxiterations - 11))
		return (0xFC0909);
	else if (inter == ((int)data->maxiterations - 10))
		return (0xdf210b);
	return (color2(inter, data));
}

int	color(int inter, t_frt *data)
{
	if (inter == ((int)data->maxiterations - 30))
		return (0x03006A);
	else if (inter == ((int)data->maxiterations - 29))
		return (0x2a0062);
	else if (inter == ((int)data->maxiterations - 28))
		return (0x300071);
	else if (inter == ((int)data->maxiterations - 27))
		return (0x35008a);
	else if (inter == ((int)data->maxiterations - 26))
		return (0x3b0097);
	else if (inter == ((int)data->maxiterations - 25))
		return (0x4300b1);
	else if (inter == ((int)data->maxiterations - 24))
		return (0x3a00b4);
	else if (inter == ((int)data->maxiterations - 23))
		return (0x2440ba);
	else if (inter == ((int)data->maxiterations - 22))
		return (0x0071c0);
	else if (inter == ((int)data->maxiterations - 21))
		return (0x00a0c4);
	return (color1(inter, data));
}
