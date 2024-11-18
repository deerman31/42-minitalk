/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 07:08:15 by ykusano           #+#    #+#             */
/*   Updated: 2023/02/11 09:46:40 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include "../libft/libft.h"

# define MODIFIER "cspdiuxX%"
# define S_NULL "(null)"

typedef struct s_sc
{
	va_list		ap;
	int			count;
	const char	*format;
}				t_sc;

int		ft_printf(const char *format, ...);
int		x_convert(unsigned int u, const char sign);
int		p_convert(uintptr_t p);
int		u_putnbr(unsigned int n);
int		di_putnbr(int n);

int		c_print(struct s_sc *text);
int		s_print(struct s_sc *text);
int		p_print(struct s_sc *text);
int		di_print(struct s_sc *text);
int		ux_print(struct s_sc *text, const char sign);

#endif
