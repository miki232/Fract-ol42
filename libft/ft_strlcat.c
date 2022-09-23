/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:00:35 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/28 10:00:37 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*temp;
	char			*ll;
	size_t			len;

	temp = (char *)ft_memchr(dest, '\0', size);
	if (temp == NULL)
		return (size + ft_strlen(src));
	ll = (char *)src;
	len = (size_t)(temp - dest) + ft_strlen(ll);
	while ((size_t)(temp - dest) < size - 1 && *ll != '\0')
	{
		*temp = *ll;
		temp++;
		ll++;
	}
	*temp = '\0';
	return (len);
}
