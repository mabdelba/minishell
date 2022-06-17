/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:41:29 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:30 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_first0(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	size_t	first_i;

	i = 0;
	j = 0;
	first_i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (j == ft_strlen(set))
		{
			first_i = i;
			break ;
		}
		i++;
	}
	return (first_i);
}

static size_t	ft_last(char *s1, char *set)
{
	size_t	k;
	size_t	j;
	size_t	last_i;

	j = 0;
	last_i = 0;
	k = ft_strlen(s1) - 1;
	while (k >= 0 && s1[k])
	{
		j = 0;
		while (set[j] && s1[k] && set[j] != s1[k])
			j++;
		if (j == ft_strlen(set))
		{
			last_i = k;
			break ;
		}
		k--;
	}
	return (last_i);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*tab;
	size_t	i;
	size_t	j;
	size_t	first_i;
	size_t	last_i;

	if (!s1 || !set)
		return (0);
	i = 0;
	first_i = ft_first0(s1, set);
	last_i = ft_last(s1, set);
	tab = (char *) malloc((last_i - first_i + 2) * sizeof (char));
	if (tab == 0)
		return (NULL);
	if (first_i == 0 && last_i == 0)
		tab[0] = '\0';
	else
	{
		i = first_i;
		j = 0;
		while (i <= last_i && s1[i])
			tab[j++] = ((char *)s1)[i++];
		tab[j] = '\0';
	}
	return (tab);
}
