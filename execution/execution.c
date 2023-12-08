#include "../minishell.h"

int is_builtin(t_input *input_list, t_data *data)
{
    if(!input_list->args || !(*input_list->args))
        return (0);
    if(ft_strncmp(*input_list->args , "echo", CMD_LEN) == 0)
        return (echo_(input_list->args));
    else if(ft_strncmp(*input_list->args , "cd", CMD_LEN) == 0)
        return (cd(*input_list, data));
    else if(ft_strncmp(*input_list->args , "pwd", CMD_LEN) == 0)
        return (pwd());
    return (0);
}

void execution(t_input *input_list, t_data *data)
{
    t_input *tmp = input_list;
    (void)data;
    while (tmp)
    {
        if(!is_builtin(tmp , data))
            printf("Not a builtin\n");
        tmp = tmp->next;
    }
}

// check if the command is builtin
// run the command
// ecxute herdocs 
// check redirections
// create redirections files
// change the output to the last file 
// excute the command
