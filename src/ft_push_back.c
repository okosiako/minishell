/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:49:47 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/24 19:12:04 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_count_len_arr(char **res)
{
	size_t	index;

	if (!res)
		return (1);
	index = 0;
	while (res[index])
		index++;
	return (index + 1);
}

char			*ft_create_variable(char *command, t_env *my_env)
{
	t_env	*temp;

	temp = NULL;
	if (ft_strchr(command, '$'))
	{
		if ((temp = ft_find_env(ft_strchr(command, '$') + 1, my_env)))
			return (temp->content);
		else
			return (NULL);
	}
	return (NULL);
}

static void		ft_make_new_string(char **new_res, char *command, t_env *my_env)
{
	char *temp;

	temp = NULL;
	if (ft_strchr(command, '$'))
	{
		temp = ft_strsub(command, 0, (ft_strchr(command, '$') - command));
		*new_res = ft_strjoin(temp, ft_create_variable(command, my_env));
	}
	else if (ft_strchr(command, '~') && ft_get_el_by_name(my_env, "HOME"))
	{
		temp = ft_strsub(command, 0, (ft_strchr(command, '~') - command));
		*new_res =
		ft_strjoin(temp, ft_get_el_by_name(my_env, "HOME")->content);
		*new_res = ft_strjoin_free(*new_res, ft_strchr(command, '~') + 1);
	}
	else
		*new_res = ft_strdup(command);
	temp ? ft_strdel(&temp) : 0;
}

/*
** command always exist since it's a condition for getting this fuction
*/

char			**ft_push_back(char **res, char *command, t_env *my_env)
{
	char	**new_res;
	size_t	index;

	new_res = (char **)ft_memalloc(sizeof(char *) * ft_count_len_arr(res) + 1);
	index = 0;
	while ((res && res[index]))
	{
		new_res[index] = ft_strdup(res[index]);
		index++;
	}
	ft_make_new_string(&new_res[index], command, my_env);
	new_res[index + 1] = NULL;
	res ? ft_free_double_char(&res) : 0;
	return (new_res);
}
