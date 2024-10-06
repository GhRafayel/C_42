/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *node)
{
	t_list	*p_node;

	p_node = (t_list *)node;
	free(p_node);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pnt;
	t_list	*temp;

	pnt = *lst;
	if (lst != NULL && *lst != NULL)
	{
		while (pnt != NULL)
		{
			temp = pnt -> next;
			del(pnt);
			pnt = temp;
		}
	}
	*lst = NULL;
}
