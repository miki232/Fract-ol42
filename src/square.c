/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:33:55 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/05 10:42:56 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	clac2(t_frt *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore - d->oim * d->oim + d->pr;
	d->newim = d->inc * d->ore * d->oim + d->pi;
}

void	clac3(t_frt *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore * d->ore - 3 * d->ore * d->oim * d->oim + d->pr;
	d->newim = d->inc * d->ore * d->ore * d->oim
		- d->oim * d->oim * d->oim + d->pi;
}

void	clac5(t_frt *d)
{
	d->ore = d->newre;
	d->oim = d->newim;
	d->newre = d->ore * d->ore * d->ore * d->ore * d->ore - 10 * d->ore
		* d->ore * d->ore * d->oim * d->oim + 5
		* d->ore * d->oim * d->oim * d->oim * d->oim + d->pr;
	d->newim = d->inc * d->ore * d->ore * d->ore * d->ore * d->oim - 10 * d->ore
		* d->ore * d->oim * d->oim * d->oim + d->oim
		* d->oim * d->oim * d->oim * d->oim + d->pi;
}
