/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:32:55 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/19 19:25:39 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = (unsigned char *)dst;
	ps = (const unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			pd[len - 1 - i] = ps[len - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(pd, ps, len);
	return (dst);
}
