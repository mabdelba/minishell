/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normexecbash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:44:57 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/06 02:34:08 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	do_fork(t_exec ex, t_list **data, int *status1)
{
	int		p[2];
	pid_t	*exp;

	exp = ex.pid;
	checkproblem(p, exp);
	if (*exp == 0)
	{
		close(p[0]);
		if ((*data)->fd_i != 0)
			duplicate((*data)->fd_i, 0);
		if ((*data)->fd_o != 1)
			duplicate((*data)->fd_o, 1);
		if (ex.i != ex.nbcmd - 1)
			duplicate(p[1], (*data)->fd_o);
		if (builtings(ex, p[1], data))
			exec2(ex, (*data)->cmd, ft_split(getpath(ex.env), ':'), status1);
	}
	else
	{
		close(p[1]);
		duplicate(p[0], 0);
	}
}

void	do_one(t_exec ex, t_list **data, int *status1, char **env)
{
	ex.i = 0;
	if ((*data)->fd_i != 0)
		duplicate((*data)->fd_i, 0);
	if ((*data)->fd_o != 1)
		duplicate((*data)->fd_o, 1);
	if (!ft_strcmp((*data)->cmd[0], "echo"))
		ft_echo((*data)->cmd);
	else if (!ft_strcmp((*data)->cmd[0], "pwd"))
	{
		ft_pwd();
		exit (1);
	}
	else if (!ft_strcmp((*data)->cmd[0], "env"))
	{
		ft_env(env);
		exit (1);
	}
	else
		exec2(ex, (*data)->cmd, ft_split(getpath(env), ':'), status1);
}

void	do_all(t_exec ex, pid_t *pid, t_list **data, int *status1)
{
	ex.pid = pid;
	do_fork(ex, data, status1);
	*data = (*data)->next;
}

void	init(int *a, int b, char ***p1, char **p2)
{
	*a = b;
	*p1 = p2;
}

void	newpipe2(t_list **data, int nbcmd, char **env, int *status1)
{
	t_exec	ex;
	pid_t	p;
	pid_t	*pid;

	pid = malloc((nbcmd -1) * sizeof(pid_t));
	init(&(ex.nbcmd), nbcmd, &(ex.env), env);
	p = fork();
	if (p == 0)
	{
		if (nbcmd == 1)
			do_one(ex, data, status1, env);
		else
		{
			ex.i = -1;
			while (++ex.i < nbcmd)
				do_all(ex, &pid[ex.i], data, status1);
			ex.i = -1;
			while (++ex.i < nbcmd)
				waitpid(pid[ex.i], NULL, 0);
			exec2(ex, (*data)->cmd, ft_split(getpath(env), ':'), status1);
		}
	}
	else
		wait(NULL);
	free(pid);
}
