/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghazary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:46 by rghazary          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:49 by rghazary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_node;
    t_list *current;

    while (lst != NULL)
    {
        new_node = ft_lstnew(f(lst -> content));
        if (new_node == NULL)
        {
            ft_lstclear(new_list, del);
            return (NULL);
        }
        if (new_list == NULL)
        {
            new_list = new_node;
        }
        else
        {
            current = new_list;
            while (current->next != NULL)
                current = current->next;
                current->next = new_node;
        }
        lst = lst->next;
    }
    return (new_list);
}
