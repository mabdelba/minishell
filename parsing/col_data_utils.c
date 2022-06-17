/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:53:14 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:17:43 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mcount(char **str)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			compt++;
		i++;
	}
	return (i - compt);
}

char	**reduce(char **str)
{
	int		i;
	int		j;
	char	**tab;

	i = mcount(str);
	tab = malloc((i + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][0] != '\0')
		{
			tab[j] = ft_strdup(str[i]);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_cleaning(char **str, int *drp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (drp[i] == 1)
		{
			if (str[i][ft_strlen(str[i]) - 1] == '>'
				|| str[i][ft_strlen(str[i]) - 1] == '<')
			{
				free(str[i + 1]);
				str[i + 1] = ft_strdup("");
			}
			if (ft_strchrp(str[i]))
			{
				free(str[i]);
				str[i] = ft_strdup("");
			}
		}
		i++;
	}
}

void	remplir_tab(char *str, int *z, int *tab, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] == c)
			{
				tab[*z] = 1;
				(*z)++;
				i++;
			}
			else
			{
				tab[*z] = 0;
				(*z)++;
			}
		}
		i++;
	}
}

int	*sort_infil(t_char2 strct, char **str, int *drp, char c)
{
	int	*tab;
	int	i;
	int	j;
	int	z;

	i = 0;
	tab = malloc((ft_leng(strct.her) + ft_leng(strct.inf) + 1) * sizeof(int));
	if (!tab)
		return (NULL);
	z = 0;
	while (str[i])
	{
		j = 0;
		if (drp[i] == 1)
			remplir_tab(str[i], &z, tab, c);
		i++;
	}
	tab[z] = -1;
	return (tab);
}
