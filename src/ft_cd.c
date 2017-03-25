/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:11:50 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 16:02:36 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include <dirent.h>

static char	*ft_return_new_path(char *command_line, t_env *home)
{
	char *path;
	char *new_path;

	path = NULL;
	path = getcwd(path, PATH_MAX);
	new_path = command_line ? ft_strjoin_n(path, "/", command_line) :
								ft_strdup(home->content);
	ft_strdel(&path);
	return (new_path);
}

static char	*ft_set_path_name(char *command_line, t_env *my_env)
{
	char	*new_path;
	t_env	*home;

	new_path = NULL;
	home = NULL;
	if ((!(home = ft_get_el_by_name(my_env, "HOME")) && !command_line) ||
		ft_strequ(command_line, "~"))
		ft_report_errors("cd", NO_HOME_VAR);
	else if (command_line && command_line[0] == '/')
		new_path = ft_strdup(command_line);
	else if (ft_strequ(command_line, "-"))
	{
		if (!ft_get_el_by_name(my_env, "OLDPWD"))
			ft_report_errors("cd", NO_OLDPWD_VAR);
		else
			new_path = ft_strdup(ft_get_el_by_name(my_env, "OLDPWD")->content);
	}
	else
		new_path = ft_return_new_path(command_line, home);
	return (new_path);
}

_Bool		ft_can_be_read(char *new_path, char *command_line)
{
	struct stat	check;

	if (stat(new_path, &check))
		return (ft_report_errors(command_line, NO_FILE_DIR));
	if (!S_ISDIR(check.st_mode))
		return (ft_report_errors(command_line, IS_FILE));
	if (access(new_path, X_OK))
		return (ft_report_errors(command_line, PERMIS_DEN));
	return (TRUE);
}

void		ft_change_elem_cd(t_env **my_env, char *path, char *env_name)
{
	t_env	*list_name;
	char	*temp_name_with_equal;

	list_name = NULL;
	temp_name_with_equal = NULL;
	if ((list_name = ft_get_el_by_name(*my_env, env_name)))
		ft_change_content(list_name, path);
	else
	{
		temp_name_with_equal = ft_strjoin(env_name, "=");
		ft_setenv(my_env, temp_name_with_equal);
		ft_change_content(ft_get_el_by_name(*my_env, env_name), path);
		ft_strdel(&temp_name_with_equal);
	}
}

void		ft_cd(t_env **my_env, char *command_line)
{
	char	*path;
	char	*new_path;

	path = NULL;
	new_path = NULL;
	if ((new_path = ft_set_path_name(command_line, *my_env)))
	{
		if (ft_can_be_read(new_path, command_line))
		{
			path = getcwd(path, PATH_MAX);
			if (!(chdir(new_path)))
			{
				ft_change_elem_cd(my_env, path, "OLDPWD");
				ft_strdel(&path);
				path = getcwd(path, PATH_MAX);
				ft_change_elem_cd(my_env, path, "PWD");
			}
			ft_strdel(&path);
		}
		ft_strdel(&new_path);
	}
}
