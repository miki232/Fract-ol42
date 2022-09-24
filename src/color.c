/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:14:55 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/24 18:33:26 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

float	huetorgb(float v1, float v2, float vH)
{
	if (vH < 0)
		vH += 1;
	if (vH > 1)
		vH -= 1;
	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1)
		return (v2);
	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return (v1);
}

t_rgb	hlstorgb(t_hsl hsl)
{
	t_rgb	rgb;
	float	v1;
	float	v2;
	float	hue;

	if (hsl.s == 0)
	{
		rgb.r = (unsigned char)(hsl.l * 255);
		rgb.g = (unsigned char)(hsl.l * 255);
		rgb.b = (unsigned char)(hsl.l * 255);
	}
	else
	{
		hue = (float)hsl.h / 360;
		if (hsl.l < 0.5)
			v2 = hsl.l * (1 + hsl.s);
		else
			v2 = (hsl.l + hsl.s) - (hsl.l * hsl.s);
		v1 = 2 * hsl.l - v2;
		rgb.r = (unsigned char)(255 * huetorgb(v1, v2, hue + (1.0f / 3)));
		rgb.g = (unsigned char)(255 * huetorgb(v1, v2, hue));
		rgb.b = (unsigned char)(255 * huetorgb(v1, v2, hue - (1.0f / 3)));
	}
	return (rgb);
}

int	colosr(float i, int p)
{
	t_hsl	l;
	t_rgb	r;
	int		x;

	if (p == 2)
		l.h = 255 - ((int)i * 3);
	else if (p == 1)
		l.h = 300 - ((int)i * 3);
	else
		l.h = 266 - ((int)i * 10);
	l.s = 1.0f;
	l.l = 0.50f;
	r = hlstorgb(l);
	x = ((int)r.r << 16 | (int)r.g << 8 | (int)r.b);
	return (x);
}

int	pal_mkg(int p, int i, t_frt *d)
{
	(void)d;
	if (p == 0)
		return (colosr(i, 2));
	if (p == 1)
		return (colosr(i, 1));
	if (p == 2)
		return (colosr(i, 0));
	return (0);
}

int	color2(int inter, t_frt *data)
{
	if (inter == ((int)data->maxiterations - 9))
		return (0x00b8b2);
	else if (inter == ((int)data->maxiterations - 8))
		return (0x00b89e);
	else if (inter == ((int)data->maxiterations - 7))
		return (0x76b874);
	else if (inter == ((int)data->maxiterations - 6))
		return (0xa0b85e);
	else if (inter == ((int)data->maxiterations - 5))
		return (0xc6b644);
	else if (inter == ((int)data->maxiterations - 4))
		return (0xfeb500);
	else if (inter == ((int)data->maxiterations - 3))
		return (0xff8c00);
	else if (inter == ((int)data->maxiterations - 2))
		return (0xfb7700);
	else if (inter == ((int)data->maxiterations - 4))
		return (0xec4e02);
	else if (inter == ((int)data->maxiterations - 0))
		return (0xFC0909);
	return (0x03006A);
}
