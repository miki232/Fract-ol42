/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:55:08 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/24 19:05:54 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	down(t_frt *data)
{
	clear(data);
	if (data->which_fract == 3)
	{	
		data->mvy = data->mvy - 0.1 * data->fac;
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
		d->ra = 0.1;
		d->cy = 0;
	}
	else if (d->p == 1)
		d->p = 2;
	else
	{
		d->p = 0;
		d->cy = 0.4;
		d->ra = 0.5;
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
