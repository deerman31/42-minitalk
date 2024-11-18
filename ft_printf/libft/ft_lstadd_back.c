/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:30:21 by ykusano           #+#    #+#             */
/*   Updated: 2023/01/23 17:30:22 by ykusano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (lst == NULL || new == NULL)
		return ;
	last_list = ft_lstlast(*lst);
	if (last_list == NULL)
		*lst = new;
	else
		last_list->next = new;
}
