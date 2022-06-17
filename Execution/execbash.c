/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execbash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:44:57 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/06 01:07:15 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec2(t_exec ex, char **av, char **path, int *status)
{
	int		i;
	char	**arv;

	i = 0;
	arv = av;
	if (checkpath(arv[0]) == 1)
	{
		checkexec(arv[0], status);
		execve(arv[0], arv, ex.env);
	}
	else
	{
		while (checkpath(ft_strjoin_ex(ft_strjoin_ex(path[i], "/"), arv[0]))
			!= 1 && path[i])
			i++;
		if (i == ft_numofsplit(getpath(ex.env), ':'))
		{
			perror("cmd not found");
			*status = 127;
		}
		execve(ft_strjoin_ex(ft_strjoin_ex(path[i], "/"), arv[0]), arv, ex.env);
	}
}

int	builtings(t_exec ex, int outfile, t_list **data)
{
	int	ret;

	if (!ft_strcmp((*data)->cmd[0], "cd"))
		ft_cd((*data)->cmd[1]);
	else if (!ft_strcmp((*data)->cmd[0], "echo"))
		ft_echo((*data)->cmd);
	else if (!ft_strcmp((*data)->cmd[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp((*data)->cmd[0], "export"))
		ex.env = ft_export(&((*data)->cmd)[1], ex.env);
	else if (!ft_strcmp((*data)->cmd[0], "env"))
		ft_env(ex.env);
	else if (!ft_strcmp((*data)->cmd[0], "unset"))
		ex.env = ft_unset(ex.env, &((*data)->cmd)[1]);
	else
		ret = 1;
	if (!ft_strcmp((*data)->cmd[0], "pwd") || !ft_strcmp((*data)->cmd[0],
			"export") || !ft_strcmp((*data)->cmd[0], "env")
		|| !ft_strcmp((*data)->cmd[0], "unset"))
		exit(0);
	return (ret);
}
