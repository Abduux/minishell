/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahraich <ahraich@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:56:49 by mel-akhd          #+#    #+#             */
/*   Updated: 2023/12/07 21:25:13 by ahraich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	move_to_next_pipe(char **input, t_data *data)
{
	t_quotes_status	qt;
	int				arg_found;

	arg_found = 0;
	init_qt(&qt);
	while (**input)
	{
		proccess_both_quotes(**input, &qt);
		if (!is_whit_sp(**input, qt.in_dobule, qt.in_single)
			&& !is_pipe(**input, qt.in_dobule, qt.in_single))
			arg_found = 1;
		if (is_pipe(**input, qt.in_dobule, qt.in_single))
		{
			(*input)++;
			while (**input == ' ')
				(*input)++;
			if (!(**input) || !arg_found)
				unexpected_token_error(data, "|");
			break ;
		}
		(*input)++;
	}
}

t_input	*first_parse(char *input, t_data *data)
{
	t_input	*list;
	t_input	*list_begin;
	t_input	*tmp;

	list_begin = NULL;
	list = NULL;
	while (*input)
	{
		tmp = list;
		list = (t_input *)malloc(sizeof(t_input));
		if (list_begin)
			tmp->next = list;
		else 
			list_begin = list;
		list->next = 0;
		list->args = get_args(input);
		list->redirect = get_redirections(input, data);
		move_to_next_pipe(&input, data);
	}
	return (list_begin);
}

t_input	*secode_parse(t_input *list_cpy, t_data *data)
{
	int				i;
	t_input			*list_begin;
	t_redirection	*redir;

	list_begin = list_cpy;
	i = 0;
	while (list_cpy)
	{
		while (list_cpy->args[i])
		{
			list_cpy->args[i] = evaluate(list_cpy->args[i], data, 0);
			i++;
		}
		redir = list_cpy->redirect;
		while (redir)
		{
			redir->file_name = evaluate(redir->file_name, data,
					redir->type);
			redir = redir->next;
		}
		list_cpy = list_cpy->next;
		i = 0;
	}
	return (list_begin);
}

void	print_parsed_list(t_input *list_begin)
{
	int				i;
	t_redirection	*red_tmp;

	i = 0;
	while (list_begin)
	{
		ft_printf("\n");
		while (list_begin->args[i])
		{
			ft_printf("[%s]", list_begin->args[i]);
			i++;
		}
		ft_printf("\n");
		red_tmp = list_begin->redirect;
		while (red_tmp)
		{
			ft_printf("[%s][file:%s] ", 
				get_redirection_string(red_tmp->type),
				red_tmp->file_name);
			red_tmp = red_tmp->next;
		}
		list_begin = list_begin->next;
		i = 0;
		ft_printf("\n--------------------\n");
	}
}

t_input	*parser(char *input, t_data *data)
{
	t_input	*input_lst;

	input_lst = first_parse(input, data);
	input_lst = secode_parse(input_lst, data);
	if (data->syntax_error)
	{
		parse_free(input_lst);
		return (NULL);
	}
	//print_parsed_list(input_lst);
	return (input_lst);
}
