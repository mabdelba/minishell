/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:50:55 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:15:54 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	countinout(char **str, char c, int *drp)
{
	int	i;
	int	j;
	int	compt;

	i = -1;
	compt = 0;
	while (str[++i])
	{
		j = 0;
		if (drp[i] == 1)
		{
			while (str[i][j])
			{
				if (str[i][j] == c)
				{
					if (str[i][j + 1] == c)
						j++;
					else
						compt++;
				}
				j++;
			}
		}
	}
	return (compt);
}

int	sizeinout(char *str, char c, char d)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c && str[i] != d)
		i++;
	return (i);
}

void	fill_arr(t_char2 s, int *z, t_int1 p, int *i)
{
	int	j;
	int	dr;
	int	size;

	j = 0;
	while (s.arr[*i][j])
	{
		dr = 1;
		if (s.arr[*i][j] == p.c && s.arr[*i][j + 1] == p.c)
			j += 2;
		else if (s.arr[*i][j] == p.c && s.arr[*i][j + 1] != p.c)
		{
			size = sizeinout(s.arr[*i] + j + 1, p.c, p.d);
			if (size == 0)
			{
				j = 0;
				size = sizeinout(s.arr[++(*i)] + j, p.c, p.d);
				dr = 0;
			}
			s.tab[(*z)++] = ft_substr(s.arr[*i], j + dr, size);
			j += size;
		}
		if (dr == 1)
			j++;
	}	
}

char	**checkinout(char **str, char c, char d, int *drp)
{
	t_char2	s;
	t_int1	p;
	int		i;
	int		z;

	s.tab = malloc((countinout(str, c, drp) + 1) * sizeof(char *));
	s.arr = str;
	p.c = c;
	p.d = d;
	if (!s.tab)
		return (NULL);
	i = 0;
	z = 0;
	while (str[i])
	{
		if (drp[i] == 1)
			fill_arr(s, &z, p, &i);
		i++;
	}
	s.tab[z] = NULL;
	return (s.tab);
}
