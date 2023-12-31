/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:48:41 by mel-akhd          #+#    #+#             */
/*   Updated: 2023/12/08 11:14:26 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value_from_env(const char *name, t_env *env)
{
	if(!name)
		return (NULL);
	while (env)
	{
		if (ft_strncmp(env->name, name, PATH_MAX) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*expand_variable(char **word, t_env *env )
{
	int		variable_length;
	char	*variable_start;
	char	*variable_name;
	char	*variable_value;

	(*word)++;
	variable_start = *word;
	while (**word && is_valid_identifier_char(**word, *word - variable_start))
		(*word)++;
	variable_length = *word - variable_start;
	variable_name = (char *)malloc(sizeof(char) * (variable_length + 1));
	ft_strlcpy(variable_name, variable_start, variable_length + 1);
	variable_value = get_value_from_env(variable_name, env);
	free(variable_name);
	return (variable_value);
}
