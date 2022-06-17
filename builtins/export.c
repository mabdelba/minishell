/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:05:39 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:15:08 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_search(char **env, char *str)
{
	int		i;
	char	**split1;
	char	**split2;

	i = 0;
	while (env[i])
	{
		split1 = ft_split(env[i], '=');
		split2 = ft_split(str, '=');
		if (!ft_strcmp(split1[0], split2[0]))
		{
			ft_free(split1);
			ft_free(split2);
			return (1);
		}
		ft_free(split1);
		ft_free(split2);
		i++;
	}
	return (0);
}

int	ft_leng2(char **env, char **str)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		if (!ft_search(env, str[i]))
			compt++;
		i++;
	}
	return (compt);
}

void	testalnum(char *str)
{
	int		j;
	char	**spl;
	char	*var;

	j = 0;
	spl = ft_split(str, '=');
	var = spl[0];
	while (ft_isalnum(var[j]))
		j++;
	if (j < ft_strlen(var))
	{
		printf("error\n");
		free(str);
		str = ft_strdup("");
	}
	ft_free(spl);
}

void	test_error(char **str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i][0]) || str[i][0] == '=')
		{
			printf("error\n");
			free(str[i]);
			str[i] = ft_strdup("");
		}
		else if (!ft_strchr(str[i], '='))
		{
			free(str[i]);
			str[i] = ft_strdup("");
		}
		else
			testalnum(str[i]);
	}
}

char	**ft_export(char **str, char **env)
{
	char	**tab;
	int		i;
	int		j;
	int		z;
	char	**str2;

	z = -1;
	i = -1;
	test_error(str);
	str2 = reduce(str);
	tab = malloc((ft_leng(env) + ft_leng(str2) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (env[++i])
	{
		if (!ft_search(str2, env[i]))
			tab[++z] = ft_strdup(env[i]);
	}
	j = -1;
	while (str2[++j])
		tab[++z] = ft_strdup(str2[j]);
	tab[++z] = NULL;
	ft_free(str2);
	ft_free(env);
	return (tab);
}

// int	main(int ac, char **av, char **env)
// {
// 	char **tab;
// 	char **tab2;
// 	int size;

// 	size = ft_leng(env);
// 	tab = malloc((size + 2) * sizeof(char *));
// 	if(!tab)
// 		return 0;
// 	tab = ft_export(&av[1], env);
// 	// ft_unset(tab, "med", tab2);
// 	ft_env(tab);
// //	ft_env(env);
// }