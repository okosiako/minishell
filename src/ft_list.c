/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:55:51 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 17:57:39 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	the_len_of_word(char *command, char c)
{
	return (ft_strchr(command, c) - command);
}

t_env			*ft_make_one_elem(char *env)
{
	t_env	*new_elem;
	size_t	len;

	new_elem = ft_memalloc(sizeof(t_env));
	len = the_len_of_word(env, '=');
	new_elem->name = ft_strsub(env, 0, len);
	new_elem->content = ft_strsub(env, len + 1, ft_strlen(env) - len);
	new_elem->next = NULL;
	return (new_elem);
}

void			ft_list_push_back(t_env **my_env, t_env *new_elem)
{
	t_env	*temp;

	if (!*my_env)
		*my_env = new_elem;
	else
	{
		temp = *my_env;
		while (temp->next)
			temp = temp->next;
		temp->next = new_elem;
	}
}

void			ft_unset_element(t_env **my_env, char *command_line)
{
	t_env	*env;
	t_env	*prev;
	t_env	*root;

	env = NULL;
	root = *my_env;
	if (ft_strequ((*my_env)->name, command_line))
		*my_env = (*my_env)->next;
	else
	{
		while (root->next)
		{
			prev = root;
			root = root->next;
			if (ft_strequ(root->name, command_line))
			{
				prev->next = root->next;
				ft_delete_env(&root);
				ft_memdel((void **)&root);
				break ;
			}
		}
	}
	root = *my_env;
}

/*
** delete env element
*/

void			ft_delete_env(t_env **root)
{
	ft_strdel(&(*root)->name);
	ft_strdel(&(*root)->content);
}
