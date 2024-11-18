/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:59 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/18 13:37:14 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*nd;
	const unsigned char	*ns;
	size_t				i;

	if (dst == src || n == 0)
		return (dst);
	nd = (unsigned char *)dst;
	ns = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		nd[i] = ns[i];
		i++;
	}
	return (nd);
}
