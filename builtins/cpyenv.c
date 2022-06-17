/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:39:26 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:14:57 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**myenv(char **env)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	size = ft_leng(env);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
