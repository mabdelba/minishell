/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:23:21 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:55 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	char_dup(char *buff, char c)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == c && buff[i + 1] == c)
			return (1);
		i++;
	}
	return (0);
}

int	longueur(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

void	incrementatin(int *i, char *buff, char c, int *flg)
{
	int	size;

	(*i)++;
	size = longueur(buff + (*i), c);
	if (size == -1)
		*flg = 1;
	(*i) += size;
}

int	check_quotes(char *buff, char c, char d)
{
	int	i;
	int	size;
	int	flg;

	i = 0;
	while (buff[i])
	{
		flg = 0;
		if (buff[i] == c)
		{
			incrementatin(&i, buff, c, &flg);
			if (flg == 1)
				return (1);
		}
		else if (buff[i] == d)
		{
			incrementatin(&i, buff, d, &flg);
			if (flg == 1)
				return (1);
		}
		else if (buff[i] == ';' || buff[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

int	ft_parsing(char *buff)
{
	char	**split;
	int		len;

	split = ft_split(buff, ' ');
	len = ft_leng(split);
	if (!ft_strcmp(split[len - 1], "|") || char_dup(buff, '|')
		|| check_quotes(buff, '"', '\'') || !ft_strcmp(split[0], "|"))
		return (1);
	ft_free(split);
	return (0);
}
