/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:33:36 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/07 21:24:36 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int pwd(void)
{
	char	cwdir[PATH_MAX];

	if(!getcwd(cwdir, PATH_MAX))
		write(2 , "Error accured !\n", 17);
	else
		printf("%s\n", cwdir);
	return (1);
}