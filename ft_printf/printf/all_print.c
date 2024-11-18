/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 06:27:30 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/11 06:27:32 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	c_print(struct s_sc *text)
{
	char	c;

	c = (char)va_arg(text->ap, int);
	if (write (1, &c, 1) == -1)
		return (-1);
	text->count += 1;
	return (1);
}

int	s_print(struct s_sc *text)
{
	char	*s;
	ssize_t	count;

	s = va_arg(text->ap, char *);
	if (s == NULL)
		count = write (1, S_NULL, ft_strlen(S_NULL));
	else
		count = write (1, s, ft_strlen(s));
	if (count == -1)
		return (-1);
	text->count += (int)count;
	return (1);
}

int	p_print(struct s_sc *text)
{
	uintptr_t	p;
	ssize_t		count;

	p = (uintptr_t)va_arg(text->ap, void *);
	count = p_convert(p);
	if (count == -1)
		return (-1);
	text->count += (int)(count);
	return (1);
}

int	di_print(struct s_sc *text)
{
	int			d;
	ssize_t		count;

	d = va_arg(text->ap, int);
	count = di_putnbr(d);
	if (count == -1)
		return (-1);
	text->count += (int)count;
	return (1);
}

int	ux_print(struct s_sc *text, const char sign)
{
	unsigned int	u;
	ssize_t			count;

	u = va_arg(text->ap, unsigned int);
	if (sign == 'x' || sign == 'X')
		count = x_convert(u, sign);
	else
		count = u_putnbr(u);
	if (count == -1)
		return (-1);
	text->count += (int)count;
	return (1);
}
