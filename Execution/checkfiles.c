/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:42:57 by aelabid           #+#    #+#             */
/*   Updated: 2022/05/30 12:25:19 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	checkexec(char *path, int *status)
{
	if (access(path, X_OK) == -1)
	{
		perror("permitions");
		*status = 126;
	}
}

int	checkpath(char *path)
{
	if (access(path, F_OK) != -1)
		return (1);
	return (0);
}

void	checkrdwr(char *file, int rdwr, int fd, int *status)
{
	if ((access(file, rdwr) == -1) || (fd == -1))
	{
		perror("file problem ");
		*status = 1;
	}
}

void	checkproblem(int p[2], pid_t *pid)
{
	if (pipe(p) < 0)
	{
		perror("pipe or fork problem");
		exit(1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit (1);
	}
}

void	duplicate(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
	{
		perror("dup");
		exit (1);
	}
	close(fd1);
}
