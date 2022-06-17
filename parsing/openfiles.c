/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:59:14 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:12 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	filltab(int *tab, char *str, int *status, int inout)
{
	if (inout == 0)
	{
		*tab = open(str, O_RDONLY);
		checkrdwr(str, R_OK, *tab, status);
	}
	else if ((inout == 1) || (inout == 2))
	{
		if (inout == 1)
			*tab = open(str, O_CREAT | O_WRONLY | O_TRUNC, 00644);
		else if (inout == 2)
			*tab = open(str, O_CREAT | O_WRONLY | O_APPEND, 00644);
		checkrdwr(str, W_OK, *tab, status);
	}
	else
		*tab = heredocpipe(str, *status);
}

int	*openfiles(char **str, int inout, int *status)
{
	int	i;
	int	*tab;

	i = 0;
	while (str[i])
		i++;
	tab = malloc((i + 1) * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (str[i])
	{
		filltab(&tab[i], str[i], status, inout);
		i++;
	}
	tab[i] = -1;
	return (tab);
}
