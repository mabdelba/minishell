/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:04:14 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:15:41 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_dollars(char **str, char c, int *drp)
{
	int	i;
	int	j;
	int	compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		j = 0;
		if (drp[i] != 0)
		{
			while (str[i][j])
			{
				if (str[i][j] == c && str[i][j + 1] != '\0')
				{
					if (str[i][j + 1] == c)
						j++;
					compt++;
				}
				j++;
			}
		}
		i++;
	}
	return (compt);
}

void	fill_tab(char *str, char **tab, int *z)
{
	int	j;
	int	size;

	j = 0;
	while (str[j])
	{
		if (str[j] == '$' && str[j + 1] == '$')
		{
			tab[*z] = ft_strdup("$");
			(*z)++;
			j++;
		}
		else if (str[j] == '$' && str[j + 1] != '\0')
		{
			size = sizeinout(str + j + 1, '$', '$');
			tab[*z] = ft_substr(str, j + 1, size);
			(*z)++;
			j += size;
		}
		j++;
	}
}

char	**variables(char **str, int *drp)
{
	char	**tab;
	int		i;
	int		z;

	tab = malloc((count_dollars(str, '$', drp) + 1) * sizeof(char *));
	if (!tab)
		exit(1);
	i = 0;
	z = 0;
	while (str[i])
	{
		if (drp[i] != 0)
			fill_tab(str[i], tab, &z);
		i++;
	}
	tab[z] = NULL;
	return (tab);
}

char	*getvar(char **env, char *str)
{
	int		i;
	char	*tab;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], str) != 0 && env[i][0] == str[0])
		{
			tab = ft_strdup(ft_strchr2(env[i], '=') + 1);
			return (tab);
		}
		i++;
	}
	return (ft_strdup(""));
}

char	**compens_var(char **str, char **env, int status, int *drp)
{
	int		i;
	char	**tab;
	char	**var;

	i = 0;
	var = variables(str, drp);
	tab = malloc(sizeof(char *) * (ft_leng(var) + 1));
	if (!tab)
		exit (1);
	while (var[i])
	{
		if (!ft_strcmp(var[i], "$"))
			tab[i] = ft_strdup("5916");
		else if (!ft_strcmp(var[i], "?"))
			tab[i] = ft_strdup(ft_itoa(status));
		else
			tab[i] = getvar(env, var[i]);
		i++;
	}
	tab[i] = NULL;
	ft_free(var);
	return (tab);
}
