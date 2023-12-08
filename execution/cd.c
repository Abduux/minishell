/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:31:43 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/08 11:09:02 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_dir(const char* name, t_data *data)
{
	if (access(name , F_OK) != 0)
		printf("minishell: cd: %s: No such file or directory\n", name);
	else if (access(name, X_OK) != 0)
		printf("minishell: cd: %s: Permission denied\n", name);
	else
	{
	chdir(name);
		
	}

	//update env variables
	//update export variables 
}


int	cd(t_input cmd, t_data *data)
{
	char	*newdir;

	if (arg_count(cmd.args) == 1)
	{
		newdir =  get_value_from_env("HOME" , data->env_list); // get the home value to navigate to it 
		if(!newdir)
			printf("minishell: cd: HOME not set\n"); // if the HOME variable not set
		else
			change_dir(newdir, data); // if it set
	}
	else if (arg_count(cmd.args) > 2)
		printf("minishell: cd: too many arguments\n");
	else if (access(cmd.args[1], F_OK) == 0)
	{
		if (access(cmd.args[1], X_OK) == -1)
			return (printf("minishell: cd: %s: Permission denied\n", cmd.args[1]));
		change_dir(cmd.args[1], data);
	}
	else
		printf("minishell: cd: %s: No such file or directory\n", cmd.args[1]);
	return (1);
}
