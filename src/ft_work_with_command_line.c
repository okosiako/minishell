/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_command_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:20:07 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/24 19:08:51 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if PROMPT is set otherwise print defined prompt
*/

static void	ft_print_prompt(t_env *my_env)
{
	t_env	*prompt;

	prompt = NULL;
	ft_printf("%s", (prompt = ft_get_el_by_name(my_env, "PROMPT")) ?
								prompt->content : PROMPT);
}

/*
** every iteration read a new line;
** command_lines lines takes from ft_read() NOT formated line separated by ';'
*/

void		ft_work_with_command_line(t_env **my_env)
{
	char	**command_lines;
	size_t	index;

	command_lines = NULL;
	while (1)
	{
		ft_print_prompt(*my_env);
		if ((command_lines = ft_read()))
		{
			index = 0;
			while (command_lines[index])
			{
				ft_handle_commands(my_env, command_lines[index]);
				index++;
			}
			ft_free_double_char(&command_lines);
		}
	}
}
