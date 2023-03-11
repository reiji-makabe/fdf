/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:39 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/31 10:45:04 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*re;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (ft_lstnew((void *)0));
	re = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&re, del);
			free(re);
			re = NULL;
			break ;
		}
		ft_lstadd_back(&re, new);
		lst = lst->next;
	}
	return (re);
}
