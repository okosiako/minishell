/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:27:28 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 15:01:05 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** works with the PATH
** 1) try if it's valid command
** 2) if no check in all path's directories
*/

int		ft_path(t_env *env, char **argument_list)
{
	char	**places;
	t_env	*path_list;
	size_t	count;

	places = NULL;
	if ((path_list = ft_get_el_by_name(env, "PATH")))
		places = ft_strsplit(path_list->content, ':');
	count = 0;
	while (places && places[count] &&
		(access(ft_strjoin_n(places[count], "/", COMMAND), F_OK) == -1))
		count++;
	if ((places && places[count] &&
		access(ft_strjoin_n(places[count], "/", COMMAND), X_OK) == -1) ||
	(!access(COMMAND, F_OK) && access(COMMAND, X_OK) == -1))
		return (NOT_EXECUTE);
	if (execve((places && places[count] ?
		ft_strjoin_n(places[count], "/", COMMAND) :
		COMMAND), argument_list, ft_make_arr(env)) == 0)
		return (0);
	return (NO_COMMAND);
}

/*
** 1) check if it is a command echo, cd, setenv, unsetenv, env, exit
** 2) if it's make go to special functions (give's the unchanged string)
** 3) else work with array of pointers for line
*/

void	ft_fork(t_env *env, char **argument_list)
{
	int	error;

	if ((error = ft_path(env, argument_list)))
		error == NO_COMMAND ? ft_report_errors(COMMAND, NO_COMMAND) :
			ft_report_errors(COMMAND, NOT_EXECUTE);
	exit(EXIT_SUCCESS);
}
