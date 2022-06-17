/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:43:47 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/06 04:02:41 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	newline(int sig)
{
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	free_data(t_list **data)
{
	t_list	*temp;

	while (*data)
	{
		temp = *data;
		ft_free(temp->cmd);
		free(temp);
		*data = (*data)->next;
	}
}

void	jstexec(t_iptr *ptr, t_char2 ch, t_list **data, int **drp)
{
	ptr->status1 = 0;
	collect_data(ch, data, ptr, drp);
	if (ptr->status1 == 0)
	{
		if ((*data)->cmd[0])
		{
			if (!ft_strcmp((*data)->cmd[0], "cd") && nb_cmd(*data) == 1)
				ft_cd((*data)->cmd[1]);
			else if (!ft_strcmp((*data)->cmd[0], "export")
				&& nb_cmd(*data) == 1)
				ch.env = ft_export(&((*data)->cmd)[1], ch.env);
			else if (!ft_strcmp((*data)->cmd[0], "unset") && nb_cmd(*data) == 1)
				ch.env = ft_unset(ch.env, &((*data)->cmd)[1]);
			else
				newpipe2(data, nb_cmd(*data), ch.env, &(ptr->status1));
			if (ptr->status1 != 127 && ptr->status1 != 126)
				ptr->status = 0;
			else
				ptr->status = ptr->status1;
		}
		else
			ptr->status = 1;
		free_data(data);
	}
}

void	opn(t_list **data, char **env)
{
	int		*drp;
	t_char2	ch;
	t_iptr	ptr;

	ptr.status = 0;
	ch.env = env;
	while (1)
	{
		ch.str = readline("minishell $> ");
		if (!ch.str || ft_strcmp(ch.str, "exit") == 0)
			error3();
		if (ft_strlen(ch.str) != 0)
		{
			if (ft_parsing(ch.str))
			{
				printf("parsing error\n");
				ptr.status = 1;
			}
			else
				jstexec(&ptr, ch, data, &drp);
			add_history(ch.str);
		}
		free(ch.str);
	}
}

int	main(int ac, char **av, char **env)
{
	t_list	*data;
	char	**newenv;

	if (ac != 1 || !av)
		printf("Error\n");
	newenv = myenv(env);
	signal(SIGINT, newline);
	signal(SIGQUIT, SIG_IGN);
	opn(&data, newenv);
	return (0);
}
