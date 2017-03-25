/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:00:41 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 15:03:18 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** parse line and creating an formated argument_list
*/

static char	**ft_parse_line(char *command_line, t_env *my_env)
{
	char	**argument_list;
	char	*temp_line;
	size_t	index;
	_Bool	open_quote;

	argument_list = NULL;
	temp_line = NULL;
	index = -1;
	open_quote = FALSE;
	while (command_line[++index])
		if (command_line[index] == '\"')
			open_quote = open_quote ? FALSE : TRUE;
		else if (!ft_strchr("\t\r \n", command_line[index]) || open_quote)
			temp_line = ft_addstr(temp_line, command_line[index]);
		else if (temp_line && ft_strchr("\t\r \n", command_line[index]))
		{
			argument_list = ft_push_back(argument_list, temp_line, my_env);
			ft_strdel(&temp_line);
		}
	if (temp_line)
		argument_list = ft_push_back(argument_list, temp_line, my_env);
	temp_line ? ft_strdel(&temp_line) : 0;
	return (argument_list);
}

static void	ft_str_to_lower(char *str)
{
	size_t	index;

	index = -1;
	while (str[++index])
		str[index] = ft_tolower(str[index]);
}

/*
** if command is cd, env, setenv, unsetenv, echo - works in this process
** in other case in fork
** while in setenv for working with more arguments
*/

static void	ft_cmd_sep(t_env **my_env, char **argument_list)
{
	pid_t	pid[2];
	int		status;

	if (ft_strequ(COMMAND, ECHO))
		ft_echo(argument_list);
	else if (ft_strequ(COMMAND, CD))
		ft_cd(my_env, argument_list[1]);
	else if (ft_strequ(COMMAND, SETENV))
		ft_setenv_func(my_env, argument_list);
	else if (ft_strequ(COMMAND, UNSETENV))
		ft_unsetenv(my_env, argument_list);
	else if (ft_strequ(COMMAND, ENV))
		ft_env(*my_env);
	else
	{
		CHILD = fork();
		CHILD == 0 ? ft_fork(*my_env, argument_list) : 0;
		while ((PARENT = wait(&status)) > 0)
			;
	}
}

/*
** command_line - one string from line that was read (before '\n' or ';')
** argument_list takes from ft_parse_line FORMATED line
*/

void		ft_handle_commands(t_env **my_env, char *command_line)
{
	char	**argument_list;

	argument_list = NULL;
	argument_list = ft_parse_line(command_line, *my_env);
	if (argument_list)
	{
		ft_str_to_lower(COMMAND);
		if (ft_strequ(COMMAND, EXIT))
			exit(EXIT_SUCCESS);
		ft_cmd_sep(my_env, argument_list);
		ft_free_double_char(&argument_list);
	}
}
