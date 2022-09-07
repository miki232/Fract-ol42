/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:14:55 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/13 13:48:51 by mtoia            ###   ########.fr       */
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

	if (hsl.S == 0)
	{
		rgb.R = (unsigned char)(hsl.L * 255);
		rgb.G = (unsigned char)(hsl.L * 255);
		rgb.B = (unsigned char)(hsl.L * 255);
	}
	else
	{
		hue = (float)hsl.H / 360;
		if (hsl.L < 0.5)
			v2 = hsl.L * (1 + hsl.S);
		else
			v2 = (hsl.L + hsl.S) - (hsl.L * hsl.S);
		v1 = 2 * hsl.L - v2;
		rgb.R = (unsigned char)(255 * huetorgb(v1, v2, hue + (1.0f / 3)));
		rgb.G = (unsigned char)(255 * huetorgb(v1, v2, hue));
		rgb.B = (unsigned char)(255 * huetorgb(v1, v2, hue - (1.0f / 3)));
	}
	return (rgb);
}

int	colosr(float i, int p)
{
	t_hsl	l;
	t_rgb	r;
	int		x;

	if (p == 1)
		l.H = 366 - ((int)i * 3);
	else
		l.H = 266 - ((int)i * 10);
	l.S = 1.0f;
	l.L = 0.50f;
	r = hlstorgb(l);
	x = ((int)r.R << 16 | (int)r.G << 8 | (int)r.B);
	return (x);
}

int	pal_mkg(int p, int i, t_frt *d)
{
	if(p == 0)
		return(color(i, d));
	if(p == 1)
		return(colosr(i, 1));
	return (0);
}