/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:54:34 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:53 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_lengt(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (const char)c)
		i++;
	return (i);
}

int	ft_nbrstrs(const char *s, char c)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (s[i])
	{
		while (s[i] == (const char)c)
			i++;
		if (s[i] != '\0')
			compt++;
		while (s[i] && s[i] != (const char)c)
			i++;
	}
	return (compt);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	ft_initial(unsigned int *i, int *j)
{
	*i = -1;
	*j = -1;
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	int				j;

	if (!s)
		return (NULL);
	tab = (char **) malloc((ft_nbrstrs(s, c) + 1) * sizeof(char *));
	if (tab == 0)
		return (NULL);
	ft_initial(&i, &j);
	while (s[++i])
	{
		if (s[i] != c)
		{
			tab[++j] = ft_substr(s, i, ft_lengt(s + i, c));
			if (!tab[j])
			{
				ft_free(tab);
				return (NULL);
			}
			i = i + ft_lengt(s + i, c) - 1;
		}
	}
	tab[++j] = 0;
	return (tab);
}
