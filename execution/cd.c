/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:31:43 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/07 22:31:39 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>
#include <linux/limits.h>
	
	//step1 : save the current working directory 
	//step2 : check if the given directory is available
	//step3 : check if the use have permission to navigate to the directory
	//step4 : navigate to the path
	//step5 : update the current working directory 
	//step6 : update the old directory path
	
int	arg_count(char **args)
{
	char	**tmp;
	int		i;

	tmp = args;
	i = 0;
	while (*tmp)
	{
		i++;
		tmp++;
	}
	return(i);
}

int	cd(t_input cmd, t_data *data)
{
	char	cwdir[PATH_MAX];
	(void)data;
	
	getcwd(cwdir, PATH_MAX);
	if(!cmd.args[1])
	{
		printf("No Arguments Given Should Go To home !\n");
		chdir("/home/ali");
		// get the home directory path
		// Navigate to the home path
		//update the environmont variables!
	}
	else if (arg_count(cmd.args) > 2)
		printf("minishell: cd: too many arguments\n");
	else if (access(cmd.args[1], F_OK) == 0)
	{
		if(access(cmd.args[1], X_OK) == -1)
		{
			printf("minishell: cd: %s: Permission denied\n", cmd.args[1]);
			return (1);
		}
		printf("Go to the path given \n");	
		chdir(cmd.args[1]);
	}
	else
		printf("minishell: cd: %s: No such file or directory\n", cmd.args[1]);
	return (1);
}