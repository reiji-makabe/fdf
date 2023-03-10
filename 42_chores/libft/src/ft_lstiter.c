/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:38 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:01 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	len;

	if (lst && f)
	{
		len = ft_lstsize(lst);
		while (len-- > 0)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
