/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:59:47 by mtoia             #+#    #+#             */
/*   Updated: 2022/08/13 11:39:45 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	doubleatoi(const char *str)
{
    int i,j,flag;
    double val;
    char c;
	int sing;

	sing = 1;
    i=0;
    j=0;
    val=0;
    flag=0;
	if (str[i] == '-')
	{
		sing *= -1;
		i++;
	}
    while ((c = *(str+i))!='\0'){
        if (c!='.'){
            val =(val*10)+(c-'0');
            if (flag == 1){
                --j;
            }
        }
        if (c=='.'){ if (flag == 1) return 0; flag=1;}
        ++i;
    }
    val = val*pow(10,j);
    return (val * sing);
}