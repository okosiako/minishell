/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:30:20 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/22 10:33:00 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	res = NULL;
	if (s1 && s2)
	{
		if ((res = (char *)ft_memalloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			ft_strcat(res, s1);
			ft_strcat(res, s2);
		}
	}
	return (res);
}

char	*ft_strjoin_n(char *one, char *two, char *three)
{
	char	*res;
	size_t	size;

	if (ft_strcmp(one, "/"))
		size = ft_strlen(one) + ft_strlen(two) + ft_strlen(three);
	else
		size = ft_strlen(two) + ft_strlen(three);
	res = ft_memalloc(sizeof(char) * (size + 1));
	(ft_strcmp(one, "/")) ? res = ft_strcpy(res, one) : 0;
	res = ft_strcat(res, two);
	res = ft_strcat(res, three);
	return (res);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char *res;

	res = NULL;
	if (s1 || s2)
	{
		if ((res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			s1 ? ft_strcat(res, s1) : 0;
			s2 ? ft_strcat(res, s2) : 0;
		}
		s1 ? ft_strdel(&s1) : 0;
	}
	return (res);
}
