/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:19:08 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/24 19:22:00 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*ft_find_env(char *variable, t_env *my_env)
{
	while (my_env && !ft_strequ(my_env->name, variable))
		my_env = my_env->next;
	if (my_env)
		return (my_env);
	else
		ft_report_errors(variable, NO_VARIABLE);
	return (0);
}

t_env		*ft_get_el_by_name(t_env *my_env, char *find_name)
{
	while (my_env && !ft_strequ(my_env->name, find_name))
		my_env = my_env->next;
	if (my_env)
		return (my_env);
	return (NULL);
}

void		ft_change_content(t_env *env_copy, char *command_line)
{
	ft_strdel(&(env_copy->content));
	env_copy->content = ft_strdup(command_line);
}

size_t		ft_count_lst(t_env *my_env)
{
	size_t count;

	count = 0;
	while (my_env)
	{
		my_env = my_env->next;
		count++;
	}
	return (count);
}
