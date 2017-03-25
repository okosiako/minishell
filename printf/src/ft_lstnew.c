/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:00:54 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 12:33:09 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = NULL;
	if ((temp = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (content == NULL)
		{
			temp->content = NULL;
			temp->content_size = 0;
		}
		else
		{
			temp->content = ft_memalloc(content_size);
			ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
		}
		temp->next = NULL;
	}
	return (temp);
}
