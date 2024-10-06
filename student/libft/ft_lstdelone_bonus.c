/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *nod)
{
	t_list	*node;

	node = (t_list *)nod;
	if (node-> content != NULL)
	{
		free(node -> content);
	}
	free (node);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del(lst);
	}
}
