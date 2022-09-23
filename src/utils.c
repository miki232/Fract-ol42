/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:27:10 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/23 19:12:48 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	zoom(t_frt *data)
{
	data->zoc = data->zoc * 1.1;
	data->zo = data->zo * 1.1;
	data->fac = data->fac / 1.1;
	data->key = 1;
	clear(data);
	if (data->which_fract == 1)
	{
		mandel(data);
		data->maxiterations += 0.3;
	}
	else if (data->which_fract == 2)
	{
		julia(data);
		data->maxiterations += 0.2;
	}
	else if (data->which_fract == 3)
	{
		ff(data);
		data->maxiterations += 0.1;
	}
	return (0);
}

int	zoomout(t_frt *data)
{
	data->zoc = data->zoc / 1.1;
	data->zo = data->zo / 1.1;
	data->fac = data->fac * 1.1;
	data->key = 1;
	clear(data);
	if (data->which_fract == 1)
	{
		mandel(data);
		data->maxiterations -= 0.3;
	}
	else if (data->which_fract == 2)
	{
		julia(data);
		data->maxiterations -= 0.2;
	}
	else if (data->which_fract == 3)
	{
		ff(data);
		data->maxiterations -= 0.1;
	}
	return (0);
}

int	left(t_frt *data)
{
	clear(data);
	if (data->which_fract == 3)
	{	
		data->movex = data->movex + 0.1 * data->fac;
		ff(data);
		return (0);
	}
	data->mmx = data->mmx + 0.1 / data->zo;
	data->movex = data->movex + 0.1 / data->zo;
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	right(t_frt *data)
{
	clear(data);
	if (data->which_fract == 3)
	{	
		data->movex = data->movex - 0.1 * data->fac;
		ff(data);
		return (0);
	}
	data->mmx = data->mmx - 0.1 / data->zo;
	data->movex = data->movex - 0.1 / data->zo;
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}

int	up(t_frt *data)
{
	clear(data);
	if (data->which_fract == 3)
	{	
		data->mvy = data->mvy + 0.1 * data->fac;
		ff(data);
		return (0);
	}
	data->mvy = data->mvy + 0.1 / data->zo;
	clear(data);
	if (data->which_fract == 1)
		mandel(data);
	else if (data->which_fract == 2)
		julia(data);
	return (0);
}
