/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:39:11 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/11 06:34:58 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ntr_len(unsigned int n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ntr_create(unsigned int n)
{
	char		*str;
	size_t		len;
	size_t		i;

	len = ntr_len(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	u_putnbr(unsigned int n)
{
	char		*ntr;
	ssize_t		count;

	ntr = ntr_create(n);
	if (ntr == NULL)
		return (-1);
	count = write (1, ntr, ntr_len(n));
	if (count == -1)
	{
		free(ntr);
		return (-1);
	}
	free(ntr);
	return ((int)count);
}

int	di_putnbr(int n)
{
	unsigned int	unum;
	ssize_t			count;
	ssize_t			flag;

	flag = 0;
	if (n < 0)
	{
		unum = (unsigned int)n * -1;
		flag = write (1, "-", 1);
		if (flag == -1)
			return (-1);
	}
	else
		unum = (unsigned int)n;
	count = u_putnbr(unum);
	if (count == -1)
		return (-1);
	return ((int)(count + flag));
}
