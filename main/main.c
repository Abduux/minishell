/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:16:40 by mel-akhd          #+#    #+#             */
/*   Updated: 2023/12/08 10:45:44 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	minishell(t_data *data)
{
	char	*input;
	t_input	*input_list;

	input = readline(ANSI_COLOR_RED"minishell-$ "ANSI_COLOR_RESET);
	while (input != NULL)
	{
		data->syntax_error = 0;
		if (ft_strncmp(input, "exit", INT_MAX) == 0)
			exit(0);
		input_list = parser(input, data);
		execution (input_list, data);
		add_history(input);
		free(input);
		parse_free(input_list);
		input = readline(ANSI_COLOR_RED"minishell-$ "ANSI_COLOR_RESET);
	}
}

void	sigint_handler(int signo)
{
	(void)signo;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	**export;

	(void)av;
	(void)ac;
	export = ft_strsdup(env);
	data.env_list = get_env_list(env);
	data.export_list = get_export_list(export);
	free_strs(export);
	increase_shlvl(data.env_list);
	increase_shlvl(data.export_list);
	minishell(&data);
	free_env_list(data.env_list);
	free_env_list(data.export_list);
	return (0);
}
