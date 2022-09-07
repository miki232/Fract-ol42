/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:55:08 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/26 10:40:39 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	down(t_frt *data)
{
	clear(data);
	if (data->which_fract == 3)
	{	
		data->mvy= data->mvy - 0.1 * data->fac;
		ff(data);
		return (0);
	}
	data->mvy = data->mvy - 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

void	inv_up(t_frt *data)
{
	data->inc = data->inc + 0.01;
	data->cre = data->cre + 0.001;
	//data->Radius += 0.1;
	clear(data);
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	else if (data->which_fract == 3)
		ff(data);
}

void	inv_down(t_frt *data)
{
	data->inc = data->inc - 0.01;
	data->cre = data->cre - 0.001;
	//data->Radius -= 0.1;
	clear(data);
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	else if (data->which_fract == 3)
		ff(data);
}

void	pp(t_frt *d)
{
	clear(d);
	if (d->p == 0)
	{
		d->p = 1;
		if (d->which_fract == 3)
			new_init(d);
	}
	else
	{
		d->p=0;
		d->Cy = 0.4;
		d->Radius = 0.5;
	}
	whichfract(d);
}

int	keypress(int key, t_frt *data)
{
	if (key == ESC)
		exit(0);
	if (key == PLUS)
		zoom(data);
	if (key == MINUS)
		zoomout(data);
	if (key == LEFT || key == D)
		left(data);
	if (key == DOWN || key == W)
		down(data);
	if (key == RIGHT || key == A)
		right(data);
	if (key == UP || key == S)
		up(data);
	if (key == KB_PAGE_UP)
		inv_up(data);
	if (key == KB_PAGE_DOWN)
		inv_down(data);
	if (key == 257)
		data->key = 1;
	if (key == 46)
		pp(data);
	return (0);
}

int	pro(int x, int y, t_frt *d)
{
	if (d->key == 1 && x >= 0 && x <= 600)
	{
		if (d->zo < 27.381850)
		{
			d->mmx = d->mmx + (1.5 * (x - d->iw / 2) / (0.8 * d->zoc * d->iw));
			d->mvy = d->mvy + (y   - d->ih / 2) / (0.6 * d->zoc * d->ih);
		}
		else
		{
			d->mmx = d->mmx + (1.5 * (x - d->iw / 2) / (1 * d->zo * d->iw));
			d->mvy = d->mvy + (y   - d->ih / 2) / (1 * d->zo * d->ih); ///maybe, try to makeit easer 
		}
		d->key = 0;
	}
	return (0);
}

int	mouseclick(int keycode, int x, int y, t_frt *e)
{

	if (keycode == 1 && e->which_fract == 2 && x >= 0 && x <= 600)
	{		
		double n = 600;
		e->cre = (double)(1.5 * (x - n / 2) / (0.7 * e->zo * n)) / e->zoc;//((c / v) - (b / n));
		e->cim = (double)((y   - n / 2) / (0.5 * e->zo * n)) / e->zoc;
		clear(e);
	 	julia(e);
	}
	
	mouse(keycode, x, y, e);
 	return(0);
}

int	mouse(int button, int x, int y, t_frt *param)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		zoom(param);
	}
	else if (button == 5)
		zoomout(param);
	return (0);
}