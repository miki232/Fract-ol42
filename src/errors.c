/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:22:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/26 15:53:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error(void)
{
	ft_printf("\n---------\e[1;34mFractal list\e[0m---------\n");
	ft_printf("\n\e[35mMandelbrot \e[36m*Max Iteration*\e[0m\n");
	ft_printf("\n\e[35mJulia      \e[36m*Real Number* *Imaginary Number*\e[0m\n");
	ft_printf("\n\e[35mNewton     \e[36m*Max Iteration*\e[0m");
	print_command();
	ft_printf("\n\e[1;37mExample: ./fractol Mandelbrot 30\n");
	ft_printf("\n\e[1;37mExample: ./fractol Julia -0.70176 -0.3842\n");
	exit(0);
}

void	e_string(void)
{
	ft_printf("\e[31mERROR PARAMETERS\nInsert only numbers\n");
	exit(0);
}

void	print_command(void)
{
	ft_printf("\n\n----------\e[1;34mCOMMAND KEY\e[0m----------");
	ft_printf("\n\n--Use \e[33mW A S D\e[0m or \e[33m'Arrow Keys'\e[0m");
	ft_printf("for moving the fractal\n\n");
	ft_printf("--Use '\e[33m+\e[0m' for zoom-in\n");
	ft_printf("      '\e[33m-\e[0m' for zoom-out\n\n");
	ft_printf("--Use '\e[33mMouse wheel\e[0m' for zoom-in, zoom-out\n");
}

void	errormand(void)
{
	ft_printf("\e[31mERROR PARAMETERS\nInsert only one numbers");
	ft_printf(" for Max Iteration\nonly decimals from 5 to 200\n");
	exit(0);
}

int	ftsclose(void *data)
{
	(void)data;
	exit(0);
}
