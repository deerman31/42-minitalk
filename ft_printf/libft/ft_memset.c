/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:23:32 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/18 15:02:22 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	pc;

	ptr = (unsigned char *)b;
	pc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = pc;
		i++;
	}
	return (b);
}
