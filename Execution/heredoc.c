/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:56:55 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/06 02:34:46 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	printfinfile(int fd, char *limitter)
{
	char	*buff;

	while (1)
	{
		buff = readline("heredoc>>");
		if (!ft_strcmp_ex(buff, limitter))
			exit(1);
		write(fd, buff, ft_strlen_ex(buff));
		write(fd, "\n", 1);
	}
}

int	heredocpipe(char *limitter, int status)
{
	int		p[2];
	pid_t	pid;
	char	*str;

	signal(SIGINT, SIG_IGN);
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(p[0]);
		printfinfile(p[1], limitter);
	}
	else
	{
		wait(NULL);
		return (p[0]);
	}
	return (0);
}
