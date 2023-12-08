/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:31:43 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/08 14:02:46 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_dir(const char* path_name, t_data *data)
{
	char	olddir[PATH_MAX];

	getcwd(olddir, PATH_MAX);
	if (access(path_name , F_OK) != 0)
		printf("minishell: cd: %s: No such file or directory\n", path_name);
	else if (access(path_name, X_OK) != 0)
		printf("minishell: cd: %s: Permission denied\n", path_name);
	else
	{
		if(chdir(path_name) != 0)
		{
			printf("Could not change to the  given path ! \n");
			return (0);
		}
		//print_env_list(data->env_list);
		//printf("key = %s \nValue = %s\n", data->export_list->name , data->export_list->value);
		
		add_env(&data->env_list, "OLDPWD", olddir);
		
		//print_env_list(data->export_list);
		//update_env_variables(data);
		//update_export_variables(data);
	}
	return (1);
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
	else
		change_dir(cmd.args[1], data);
	return (1);
}
