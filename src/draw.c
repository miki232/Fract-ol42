/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:36:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/26 10:19:43 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	my_mlx_pixel_put(t_frt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->btxp / 8));
	*(unsigned int *)dst = color;
}

int	clear(t_frt *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, data->iw, data->ih);
	data->addr = mlx_get_data_addr(data->img, &data->btxp, &data->line_length, &data->endian);
	return (0);
}

void	put2screen(t_frt *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

int	color1(int inter, t_frt *data)
{
	int	max;

	max = data->maxiterations;
	if (inter == (max - 20))
		return (0x00b8b2);
	else if (inter == (max - 19))
		return (0x00b89e);
	else if (inter == (max - 18))
		return (0x76b874);
	else if (inter == (max - 17))
		return (0xa0b85e);
	else if (inter == (max - 16))
		return (0xc6b644);
	else if (inter == (max - 15))
		return (0xfeb500);
	else if (inter == (max - 14))
		return (0xff8c00);
	else if (inter == (max - 13))
		return (0xfb7700);
	else if (inter == (max - 12))
		return (0xec4e02);
	else if (inter == (max - 11))
		return (0xFC0909);
	else if (inter == (max - 10))
		return (0xdf210b);
	return (0x03006A);
}

int	color(int inter, t_frt *data)
{
	int	max;
	
	max = data->maxiterations;
	if (inter == (max - 30))
		return (0x03006A);
	else if (inter == (max - 29))
		return (0x2a0062);
	else if (inter == (max - 28))
		return (0x300071);
	else if (inter == (max - 27))
		return (0x35008a);
	else if (inter == (max - 26))
		return (0x3b0097);
	else if (inter == (max - 25))
		return (0x4300b1);
	else if (inter == (max - 24))
		return (0x3a00b4);
	else if (inter == (max - 23))
		return (0x2440ba);
	else if (inter == (max - 22))
		return (0x0071c0);
	else if (inter == (max - 21))
		return (0x00a0c4);
	return (color1(inter, data));
}