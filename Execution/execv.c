/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:45:16 by aelabid           #+#    #+#             */
/*   Updated: 2022/05/30 12:28:21 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec(char **av, int poscmd, char **path, char **env)
{
	int		i;
	char	**arv;

	i = 0;
	arv = ft_split(av[poscmd], ' ');
	if (checkpath(arv[0]) == 1)
		execve(arv[0], arv, env);
	else
	{
		while (checkpath(ft_strjoin_ex(ft_strjoin_ex(path[i], "/"), arv[0]))
			!= 1 && path[i])
			i++;
		if (i == ft_numofsplit(getpath(env), ':'))
		{
			perror("cmd not found");
			exit(1);
		}
		execve(ft_strjoin_ex(ft_strjoin_ex(path[i], "/"), arv[0]), arv, env);
	}
}
