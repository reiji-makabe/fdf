/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:37 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 05:24:28 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_p;

	if (lst && del)
	{
		while (*lst)
		{
			next_p = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next_p;
		}
	}
}
