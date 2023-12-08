/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:42:45 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/07 12:09:37by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int    n_option(char *arg) 
{
	int	i;
	
	i = 0;
    if (!arg || arg[i] != '-')
		return (0);
	while (arg[++i])
    {
        if(arg[i] != 'n')
            return (0);
	}
	if(i == 1)
		return (0);
    return (1);
}


int	echo_(char **args)
{
	int	new_line;
	int	i;

    new_line = 1;
	i = 1;
    while (n_option(args[i]))
    {
        new_line = 0;
        i++;
    }
    while (args[i])
    {
        printf("%s", args[i]);
        if(args[++i])
            printf(" ");
    }
    if(new_line){
        printf("\n");
	}
	return (1);
}
