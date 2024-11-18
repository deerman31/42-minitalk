/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:39:11 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/15 17:52:58 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_count(unsigned int n)
{
	size_t		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	put_helper(unsigned int n, int fd)
{
	if (n >= 10)
	{
		put_helper(n / 10, fd);
		put_helper(n % 10, fd);
	}
	else
		if (ft_putchar_fd(n + '0', fd) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unum;
	int				flag;

	flag = 0;
	if (n < 0)
	{
		unum = (unsigned int)(n * -1);
		flag = ft_putchar_fd('-', fd);
		if (flag == -1)
			return (-1);
		if (put_helper(unum, fd) == -1)
			return (-1);
	}
	else
	{
		unum = (unsigned int)n;
		if (put_helper(unum, fd) == -1)
			return (-1);
	}
	return (nbr_count(unum) + flag);
}
