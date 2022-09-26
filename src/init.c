/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:06:39 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/26 15:50:46 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	checkmand(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= '0' && str[count] <= '9'))
			count++;
		else
			return (1);
	}
	return (0);
}

int	check(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= '0' && str[count] <= '9')
			|| (str[count] == '-' || str[count] == '.'))
			count++;
		else
			return (1);
	}
	return (0);
}

void	mand_init(t_frt *d, t_args *arg)
{
	if (arg->argc == 3)
	{
		if (checkmand(arg->argv[2]))
			errormand();
		else if (doubleatoi(arg->argv[2]) < 5 || doubleatoi(arg->argv[2]) > 200)
			errormand();
		d->maxiterations = doubleatoi(arg->argv[2]);
	}
	else if (arg->argc > 3)
		errormand();
	else
		d->maxiterations = 40;
	d->which_fract = 1;
	d->inc = 2;
}

void	jul_init(t_frt *d, t_args *arg)
{
	d->maxiterations = 30;
	d->which_fract = 2;
	d->cre = -0.8;
	d->cim = 0.156;
	if (arg->argc == 3)
	{
		ft_printf("\e[31mError missing parameters\nInsert 2 parameters");
		ft_printf(", only numbers are allowed\n");
		ft_printf("Ex. /fractol Julia (*Real num*) (*Imaginary num*)\n");
		exit(0);
	}
	if (arg->argc == 4)
	{
		if (!check(arg->argv[2]) && !check(arg->argv[3]))
		{
			d->cre = doubleatoi(arg->argv[2]);
			d->cim = doubleatoi(arg->argv[3]);
		}
		else
			e_string();
	}
}

void	new_init(t_frt *d, t_args *arg)
{
	d->xx = 0;
	d->yy = 0;
	(void)arg;
	if (arg->argc == 3)
	{
		if (checkmand(arg->argv[2]))
			errornewt();
		else if (doubleatoi(arg->argv[2]) < 5 || doubleatoi(arg->argv[2]) > 30)
			errornewt();
		d->maxiterations = doubleatoi(arg->argv[2]);
	}
	d->inc = 1;
	d->key = 0;
	d->which_fract = 3;
	d->cy = 0;
	d->cx = 0;
	d->ra = 0.1;
}
