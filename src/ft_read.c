/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:03:15 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/24 19:06:55 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** reads line, waits for closed " and returns a splited by ';' arrray of strings
*/

char	**ft_read(void)
{
	char	**res;
	char	*buff_command_line;
	char	*buff;
	_Bool	open_quote;

	res = NULL;
	buff_command_line = NULL;
	open_quote = FALSE;
	buff = ft_strnew(1);
	while ((read(STDIN_FILENO, buff, 1)))
	{
		if (buff[0] == '\"')
			open_quote = open_quote ? FALSE : TRUE;
		else if (buff[0] == '\n' && open_quote)
			ft_printf(">dquote ");
		buff_command_line = ft_strjoin_free(buff_command_line, buff);
		if (buff[0] == '\n' && !open_quote)
			break ;
	}
	res = ft_strsplit(buff_command_line, ';');
	ft_memdel((void **)&buff_command_line);
	ft_memdel((void **)&buff);
	return (res);
}
