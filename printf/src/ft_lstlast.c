/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:03:40 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/22 12:46:04 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlast(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!*alst)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
