/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:06:43 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:50 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill(t_char2 ch, int *drp, int *i, int *j)
{
	int	len2;

	(*i)++;
	len2 = ft_length2(ch.s + (*i), ch.c);
	ch.tab[*j] = ft_substr(ch.s, *i, len2);
	if (ch.c == '"')
		*drp = 2;
	else
		*drp = 0;
	*i = *i + len2;
	(*j)++;
}

void	ft_allocate(char const *s, int ***drp, char ***tab)
{
	**drp = malloc((ft_sizep(s, '"', '\'') + 1) * sizeof(int));
	if (**drp == 0)
		exit(1);
	*tab = malloc((ft_sizep(s, '"', '\'') + 1) * sizeof(char *));
	if (!*tab)
		exit(1);
}

void	space(t_char2 ch, int **drp, int *j, int *i)
{
	char	*str;
	int		z;
	char	**split;

	str = ft_substr(ch.s, *i, ft_length(ch.s + (*i), '"', '\''));
	split = ft_split(str, ' ');
	z = 0;
	while (split[z])
	{
		ch.tab[*j] = split[z];
		(*drp)[*j] = 1;
		z++;
		(*j)++;
	}
	*i = (*i) + ft_length(ch.s + (*i), '"', '\'') - 1;
	free(str);
	free(split);
}

char	**ft_splitp(char const *s, char c, char d, int **drp)
{
	int		i;
	int		j;
	t_char2	ch;

	ft_allocate(s, &drp, &(ch.tab));
	i = 0;
	j = 0;
	ch.s = s;
	while (s[i])
	{
		ch.c = c;
		if (s[i] != c && s[i] != d)
			space(ch, drp, &j, &i);
		else if (s[i] == c)
			fill(ch, &(*drp)[j], &i, &j);
		else if (s[i] == d)
		{
			ch.c = d;
			fill(ch, &(*drp)[j], &i, &j);
		}
		i++;
	}
	ch.tab[j] = 0;
	(*drp)[j] = -1;
	return (ch.tab);
}
