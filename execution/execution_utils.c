/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:01:39 by ahraich           #+#    #+#             */
/*   Updated: 2023/12/08 11:02:17 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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
