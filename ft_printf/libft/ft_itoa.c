/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:53:29 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/19 17:47:53 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_count(unsigned int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	itoa_helper(char *ptr, unsigned int n, size_t len, size_t sign)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (sign == 1 && (len - 1 - i) == 0)
			ptr[0] = '-';
		else
			ptr[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	ptr[len] = '\0';
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			len;
	size_t			sign;
	unsigned int	u_num;

	ptr = "";
	sign = 0;
	if (n < 0)
	{
		u_num = (unsigned int)(n * -1);
		sign++;
	}
	else
		u_num = (unsigned int)n;
	len = itoa_count(u_num) + sign;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	itoa_helper(ptr, u_num, len, sign);
	return (ptr);
}
