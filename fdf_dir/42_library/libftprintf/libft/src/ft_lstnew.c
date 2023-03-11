/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:39 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:03 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_list;

	p_list = (t_list *)malloc(sizeof(t_list));
	if (p_list == NULL)
		return (NULL);
	p_list->content = content;
	p_list->next = NULL;
	return (p_list);
}
