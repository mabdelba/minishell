/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:41:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:15:20 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_unset(char **env, char **str)
{
	int		i;
	int		j;
	char	**tab;
	char	**spl;

	j = -1;
	while (env[++j])
	{
		i = -1;
		while (str[++i])
		{
			spl = ft_split(env[j], '=');
			if (!ft_strcmp(spl[0], str[i]))
			{
				free(env[j]);
				env[j] = ft_strdup("");
				ft_free(spl);
				break ;
			}
			ft_free(spl);
		}
	}
	tab = reduce(env);
	ft_free(env);
	return (tab);
}
