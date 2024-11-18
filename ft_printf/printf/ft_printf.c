/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:28:16 by ykusano           #+#    #+#             */
/*   Updated: 2023/03/14 01:51:07 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_sign(t_sc *text, size_t i)
{
	int		flag;

	flag = 1;
	if (text->format[i] == 'c')
		flag = c_print(text);
	else if (text->format[i] == 's')
		flag = s_print(text);
	else if (text->format[i] == '%')
	{
		flag = write(1, &text->format[i], 1);
		text->count += 1;
	}
	else if (text->format[i] == 'd' || text->format[i] == 'i')
		flag = di_print(text);
	else if (text->format[i] == 'u')
		flag = ux_print(text, text->format[i]);
	else if (text->format[i] == 'x' || text->format[i] == 'X')
		flag = ux_print(text, text->format[i]);
	else if (text->format[i] == 'p')
		flag = p_print(text);
	if (flag == -1)
		return (-1);
	return (1);
}

static int	print_specifier(t_sc *text, size_t i)
{
	ssize_t		flag;

	flag = 1;
	if (ft_strchr(MODIFIER, text->format[i]))
		flag = print_sign(text, i);
	else
	{
		flag = write (1, &text->format[i], 1);
		text->count += 1;
	}
	if (flag == -1)
		return (-1);
	return (1);
}

static int	print_branch(t_sc *text)
{
	size_t		i;
	int			flag;

	i = 0;
	flag = 1;
	while (text->format[i] != '\0')
	{
		if (text->format[i] == '%')
		{
			i++;
			flag = print_specifier(text, i);
		}
		else
		{
			flag = write (1, &text->format[i], 1);
			text->count += 1;
		}
		if (flag == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_sc		text;

	text.count = 0;
	text.format = format;
	va_start(text.ap, format);
	if (print_branch(&text) == -1)
		return (-1);
	va_end(text.ap);
	return (text.count);
}
