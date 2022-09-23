/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:59:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/23 19:20:35 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	result(const char *str, double val, int flag, int i[2])
{
	char	c;

	c = *(str + i[0]);
	while (c != '\0')
	{
		if (c != '.')
		{
			val = (val * 10) + (c - '0');
			if (flag == 1)
			{
				--i[1];
			}
		}
		if (c == '.')
		{
			if (flag == 1)
				return (0);
			flag = 1;
		}
		++i[0];
		c = *(str + i[0]);
	}
	val = val * pow(10, i[1]);
	return (val);
}

double	doubleatoi(const char *str)
{
	int		i[2];
	int		flag;
	double	val;
	int		sing;

	sing = 1;
	i[0] = 0;
	i[1] = 0;
	val = 0;
	flag = 0;
	if (str[i[0]] == '-')
	{
		sing *= -1;
		i[0]++;
	}
	return (result(str, val, flag, i) * sing);
}

int	pro(int x, int y, t_frt *d)
{
	if (d->key == 1 && x >= 0 && x <= 600)
	{
		d->mmx = d->mmx + (1.5 * (x - d->iw / 2) / (1.7 * d->zo * d->iw));
		d->mvy = d->mvy + (y - d->ih / 2) / (1.5 * d->zo * d->ih);
		d->movex = d->mmx;
		d->key = 0;
	}
	return (0);
}

int	mouseclick(int keycode, int x, int y, t_frt *d)
{
	if (keycode == 1 && d->which_fract == 2 && x >= 0 && x <= 600)
	{		
		d->cre = (double)((x - d->iw / 2) / (0.7 * d->zo * d->iw)) / d->zo;
		d->cim = (double)((y - d->ih / 2) / (0.5 * d->zo * d->ih)) / d->zo;
		d->cre *= 1.5;
		clear(d);
		julia(d);
	}
	mouse(keycode, d);
	return (0);
}

int	mouse(int button, t_frt *param)
{
	if (button == 4)
	{
		zoom(param);
	}
	else if (button == 5)
		zoomout(param);
	return (0);
}
