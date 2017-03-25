/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:26:45 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 15:45:33 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** echo function
*/

void			ft_echo(char **command_line)
{
	size_t	index;
	_Bool	n;

	index = 1;
	while (command_line[index])
	{
		if (ft_strequ(command_line[index], "-n"))
			n = TRUE;
		else
			ft_printf("%s ", command_line[index]);
		index++;
	}
	ft_printf("%s", (n ? "" : "\n"));
}

void			ft_env(t_env *my_env)
{
	while (my_env)
	{
		ft_printf("%s=", my_env->name);
		ft_printf("%s\n", my_env->content);
		my_env = my_env->next;
	}
}

void			ft_setenv_func(t_env **my_env, char **argument_list)
{
	size_t	index;

	index = 1;
	while (argument_list[index])
		ft_setenv(my_env, argument_list[index++]);
}

void			ft_unsetenv(t_env **my_env, char **command_line)
{
	size_t	index;

	index = 1;
	while (command_line[index])
	{
		ft_unset_element(my_env, command_line[index]);
		index++;
	}
}
