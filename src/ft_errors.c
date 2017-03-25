/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:42:47 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 15:50:53 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fork_errors(int error)
{
	error == NO_COMMAND ?
		ft_putstr_fd(": Command not found.\n", STDERR_FILENO) :
		ft_putstr_fd(": Not an executable file.\n", STDERR_FILENO);
	ft_putstr_fd(NORM, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

_Bool		ft_report_errors(char *str, int error)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (error == NO_VARIABLE)
		ft_putstr_fd(": Undefined variable.\n", STDERR_FILENO);
	else if (error == NO_COMMAND || error == NOT_EXECUTE)
		fork_errors(error);
	else if (error == NO_FILE_DIR)
		ft_putstr_fd(": No such file or directory.\n", STDERR_FILENO);
	else if (error == IS_FILE)
		ft_putstr_fd(": Is file.\n", STDERR_FILENO);
	else if (error == NO_HOME_VAR)
		ft_putstr_fd(": HOME variable is not set.\n", STDERR_FILENO);
	else if (error == NO_OLDPWD_VAR)
		ft_putstr_fd(": OLDPWD variable is not set.\n", STDERR_FILENO);
	else if (error == MANY_AC)
		ft_putstr_fd(" doesn't work whis extra parameters, yet.\n", 2);
	else if (error == PERMIS_DEN)
		ft_putstr_fd(": Permission denied.\n", STDERR_FILENO);
	ft_putstr_fd(NORM, STDERR_FILENO);
	return (FALSE);
}
