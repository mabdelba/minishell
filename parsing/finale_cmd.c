/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finale_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:15:39 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:17:20 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_first(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	tab = (char *)malloc((i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tab[j] = str[j];
		j++;
	}
	tab[j] = '\0';
	if (tab[0] == '\0')
	{
		free(tab);
		return (ft_strdup(""));
	}
	return (tab);
}

char	*get_str(t_char2 s, int *count, char **var, int *drp)
{
	int		i;
	char	*tab;
	char	*ptr;
	int		size;

	i = 0;
	tab = ft_first(s.old);
	i += ft_strlen(tab);
	while (s.old[i])
	{
		if (drp[i] != 0)
		{
			if (s.old[i] == '$' && s.old[i + 1] == '\0')
				tab = ft_strjoinc(tab, ft_strdup("$"));
			else if (s.old[i] == '$')
			{
				tab = ft_strjoinc(tab, ft_strdup(s.cmp[*count]));
				i += ft_strlen(var[*count]);
				(*count)++;
			}
		}
		i++;
	}
	return (tab);
}

void	remplirtab(char **tab, t_char2 s, int *count, int *drp)
{
	char	**var;

	if (!ft_strchr(s.old, '$'))
		*tab = ft_strdup(s.old);
	else
	{
		var = variables(s.arr, drp);
		*tab = get_str(s, count, var, drp);
		ft_free(var);
	}
}

char	**finale_cmd(char **old, char **env, int *drp, int status)
{
	char	**tab;
	t_char2	s;
	int		count;
	int		i;

	i = 0;
	count = 0;
	s.cmp = compens_var(old, env, status, drp);
	s.arr = old;
	tab = malloc(sizeof(char *) * (ft_leng(old) + 1));
	if (!tab)
		exit(1);
	while (old[i])
	{
		s.old = old[i];
		if (drp[i] == 1 || drp[i] == 2)
			remplirtab(&tab[i], s, &count, drp);
		else
			tab[i] = ft_strdup(old[i]);
		i++;
	}
	tab[i] = NULL;
	ft_free(s.cmp);
	return (tab);
}
