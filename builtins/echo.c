/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:49:56 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/02 02:27:20 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char	**str)
{
	int		i;
	int		n;

	i = 1;
	n = 1;
	if (!ft_strcmp(str[1], "-n"))
	{
		i++;
		n = 0;
	}
	while (str[i])
	{
		printf("%s ", str[i]);
		i++;
	}
	if (n == 0)
		exit(1);
	printf("\n");
	exit(1);
}

// int main(int ac, char **av)
// {
// 	ft_echo(&av[1]);
// }