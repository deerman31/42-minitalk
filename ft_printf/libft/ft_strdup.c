/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:39:22 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/18 21:25:27 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ps;
	size_t	len;

	len = ft_strlen(s1);
	ps = malloc(sizeof(char) * (len + 1));
	if (ps == NULL)
		return (NULL);
	ft_strlcpy(ps, s1, len + 1);
	return (ps);
}
