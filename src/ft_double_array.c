/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:16:06 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 15:47:46 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_free_double_char(char ***list)
{
	size_t index;

	index = 0;
	while ((*list)[index])
	{
		ft_strdel(&((*list)[index]));
		index++;
	}
	ft_memdel((void **)&(*list));
}

char			**ft_make_arr(t_env *my_env)
{
	size_t	numb;
	char	**res;
	size_t	index;

	numb = ft_count_lst(my_env);
	res = (char **)ft_memalloc(sizeof(char *) * (numb + 1));
	index = 0;
	while (my_env)
	{
		res[index++] = ft_strjoin_n(my_env->name, "=", my_env->content);
		my_env = my_env->next;
	}
	res[index] = NULL;
	return (res);
}

static size_t	the_len_of_word(char *command, char c)
{
	return (ft_strchr(command, c) - command);
}

void			ft_setenv(t_env **my_env, char *command_line)
{
	t_env	*env;
	t_env	*env_copy;
	char	*name;

	env = NULL;
	env_copy = *my_env;
	name = NULL;
	if (ft_strchr(command_line, '='))
	{
		name = ft_strsub(command_line, 0, the_len_of_word(command_line, '='));
		while (env_copy && !ft_strequ(env_copy->name, name))
			env_copy = env_copy->next;
		ft_strdel(&name);
		if (env_copy)
			ft_change_content(env_copy,
			&(command_line[ft_strlen(env_copy->name) + 1]));
		else
		{
			env = ft_make_one_elem(command_line);
			ft_list_push_back(my_env, env);
		}
	}
	else
		ft_report_errors(command_line, NO_FILE_DIR);
}
