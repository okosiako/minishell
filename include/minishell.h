/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okosiako <okosiako@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:27:00 by okosiako          #+#    #+#             */
/*   Updated: 2017/03/25 13:43:17 by okosiako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>

# include "../printf/include/include.h"

# define PATH		"PATH"
# define EXIT		"exit"
# define ECHO		"echo"
# define ENV		"env"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define CD			"cd"
# define PROMPT		"$> "

# define CHILD	pid[0]
# define PARENT	pid[1]

# define TRUE	1
# define FALSE	0

# define S_ISXUSR(m) (m & S_IXUSR)

/*
** ERRORS
*/

# define NO_VARIABLE	1
# define NO_COMMAND		2
# define NO_FILE_DIR	3
# define IS_FILE		4
# define NO_HOME_VAR	5
# define NO_OLDPWD_VAR	6
# define MANY_AC		7
# define PERMIS_DEN		8
# define NOT_EXECUTE	9

/*
** COLORS
*/

# define BLUE			"\e[3;34m"
# define RED			"\e[1;31m"
# define NORM			"\e[0m"

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

# define COMMAND	argument_list[0]

/*
** getting and parsing a command line
*/

void				ft_work_with_command_line(t_env **my_env);
char				**ft_read();
void				ft_handle_commands(t_env **my_env, char *command_line);

/*
** functions for hanling commands
*/

void				ft_echo(char **command_line);
void				ft_env(t_env *my_env);
void				ft_cd(t_env **my_env, char *command_line);
void				ft_setenv_func(t_env **my_env, char **command_line);
void				ft_unsetenv(t_env **my_env, char **command_line);

/*
** function for fork section
*/

int					ft_path(t_env *env, char **command);
void				ft_fork(t_env *env, char **command);

/*
** functions for lists
*/

t_env				*ft_make_one_elem(char *env);
void				ft_list_push_back(t_env **my_env, t_env *new_elem);
void				ft_unset_element(t_env	**my_env, char *command_line);
void				ft_delete_env(t_env **root);

t_env				*ft_find_env(char *variable, t_env *my_env);
t_env				*ft_get_el_by_name(t_env *my_env, char *find_name);
void				ft_change_content(t_env *env_copy, char *command_line);
size_t				ft_count_lst(t_env *my_env);

/*
** work with double array
*/

char				**ft_make_arr(t_env *my_env);
void				ft_free_double_char(char ***command_line);
void				ft_setenv(t_env **my_env, char *command_line);
char				**ft_push_back(char **res, char *command, t_env *my_env);

/*
** report errors
*/

_Bool				ft_report_errors(char *str, int error);

#endif
