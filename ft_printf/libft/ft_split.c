/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:30:52 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/23 17:30:55 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**all_free(char **strs)
{
	size_t		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_split_dup(char const *s, char c)
{
	char	*str;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

static char	**ft_split_helper(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			strs[count] = ft_split_dup(&s[i], c);
			if (strs[count] == NULL)
				return (all_free(strs));
			count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	strs[count] = NULL;
	return (strs);
}

static size_t	split_count(char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = ft_calloc((split_count(s, c) + 1), sizeof(char *));
	if (strs == NULL)
		return (NULL);
	return (ft_split_helper(strs, s, c));
}
