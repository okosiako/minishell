/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:27:15 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 14:51:47 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** creates envirnmant variables
*/

static t_env	*ft_create_envirm_var(t_env **my_env, char **ev)
{
	size_t	count;
	t_env	*temp;

	count = 0;
	while (ev[count])
	{
		temp = ft_make_one_elem(ev[count]);
		ft_list_push_back(my_env, temp);
		count++;
	}
	return (*my_env);
}

/*
** 1) make a copy of ev to my_ev
** 2) read line and work with it
*/

int				main(int ac, char **av, char **ev)
{
	t_env	*my_env;

	if (ac > 1)
	{
		ft_report_errors(av[0], MANY_AC);
		return (0);
	}
	my_env = NULL;
	my_env = ft_create_envirm_var(&my_env, ev);
	ft_work_with_command_line(&my_env);
	while (my_env)
	{
		ft_delete_env(&my_env);
		my_env = my_env->next;
	}
	ft_memdel((void **)&my_env);
	return (0);
}
