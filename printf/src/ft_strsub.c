/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:43:46 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/24 18:57:49 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;
	char *temp;

	res = NULL;
	if (s)
	{
		if ((res = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		{
			temp = res;
			while (*(s + start) && len--)
			{
				*temp++ = *(s + start++);
			}
		}
	}
	return (res);
}
