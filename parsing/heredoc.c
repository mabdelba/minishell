/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:09:29 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:23 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	countoutin(char **str, char c, int *drp)
{
	int		i;
	int		j;
	int		compt;

	i = -1;
	compt = 0;
	while (str[++i])
	{
		j = 0;
		if (drp[i] == 1)
		{
			while (str[i][j])
			{
				if (str[i][j] == c && str[i][j + 1] == c)
				{
					j++;
					compt++;
				}
				j++;
			}
		}
	}
	return (compt);
}

void	utile(t_char2 s, int *i, int *z, char c)
{
	int		j;
	t_int1	v;

	j = 0;
	while (s.arr[*i][j])
	{
		v.dr = 1;
		if (s.arr[*i][j] == c && s.arr[*i][j + 1] == c)
		{
			j++;
			v.size = sizeinout(s.arr[*i] + j + 1, '>', '<');
			if (v.size == 0)
			{
				(*i)++;
				j = 0;
				v.size = sizeinout(s.arr[*i] + j, '>', '<');
				v.dr = 0;
			}
			s.tab[*z] = ft_substr(s.arr[*i], j + v.dr, v.size);
			j += v.size;
			(*z)++;
		}
		if (v.dr == 1)
			j++;
	}	
}

char	**heredoc(char **str, char c, int *drp)
{
	t_char2	s;
	int		size;
	int		i;
	int		z;
	int		dr;

	s.tab = malloc((countoutin(str, c, drp) + 1) * sizeof(char *));
	if (!s.tab)
		return (NULL);
	s.arr = str;
	i = 0;
	z = 0;
	while (str[i])
	{
		if (drp[i] == 1)
			utile(s, &i, &z, c);
		i++;
	}
	s.tab[z] = NULL;
	return (s.tab);
}
