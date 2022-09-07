/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:06:39 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/26 10:17:20 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void e_string()
{
	printf("ERROR PARAMETERS\nInsert only numbers\n");
	exit(0);
}

int ft_isstring(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if(ft_isalpha(str[count]))
			return (0);
		count++;
	}
	return (1);
}

void	mand_init(t_frt *d)
{
	d->maxiterations = 30;
	d->which_fract = 1;
	d->inc = 2;
}

void	jul_init(t_frt *d, t_args *arg)
{
	d->maxiterations = 30;
	d->which_fract = 2;
	d->cre =  -0.8;
	d->cim = 0.156;
	if (arg->argc == 3)
	{
		ft_printf("Error missing parameters\nInsert 2 parameters\n");
		ft_printf("Ex. /fractol Julia (*Real num*) (*Imaginary num*)\n");
		exit(0);
	}
	if (arg->argc == 4)
	{
		if (ft_isstring(arg->argv[2]) && ft_isstring(arg->argv[3]) )
		{
			d->cre = doubleatoi(arg->argv[2]);
			d->cim = doubleatoi(arg->argv[3]);
		}
		else
			e_string();
	}
}

void	new_init(t_frt *d)
{
	d->maxiterations = 25;
	d->inc = 1;
	d->key = 0;
	d->which_fract = 3;
	d->Cy = 0;
	d->Cx = 0;
	d->Radius = 0.1;
}