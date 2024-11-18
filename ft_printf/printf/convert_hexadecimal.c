/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:27:53 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/11 06:32:13 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	hexadecimal_len(size_t n)
{
	size_t		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*convert_hexadecimal(size_t num)
{
	size_t		i;
	size_t		len;
	char		*str;

	len = hexadecimal_len(num);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[len - i - 1] = (num % 16) + '0';
		if (str[len - i - 1] >= ':' && str[len - i - 1] <= '?')
			str[len - i - 1] += 39;
		num /= 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	x_convert(unsigned int u, const char sign)
{
	size_t		len;
	size_t		i;
	char		*str;

	len = hexadecimal_len((size_t)u);
	str = convert_hexadecimal((size_t)u);
	if (str == NULL)
		return (-1);
	i = 0;
	while (sign == 'X' && i < len)
	{
		if (!ft_isdigit(str[i]))
			str[i] -= ' ';
		i++;
	}
	if (write (1, str, len) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	p_convert(uintptr_t p)
{
	size_t		len;
	char		*str;

	len = hexadecimal_len((size_t)p);
	str = convert_hexadecimal((size_t)p);
	if (str == NULL)
		return (-1);
	if (write (1, "0x", 2) == -1)
	{
		free(str);
		return (-1);
	}
	if (write (1, str, len) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len + 2);
}
