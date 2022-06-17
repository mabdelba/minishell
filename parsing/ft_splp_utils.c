/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:38:05 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:16:46 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_length(const char *s, char c, char d)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (const char)c && s[i] != (const char)d)
		i++;
	return (i);
}

size_t	ft_length2(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (const char)c)
		i++;
	return (i);
}

void	increment(int *i, char const *s, char c, int *count)
{
	int	len2;

	(*i)++;
	len2 = ft_length2(s + (*i), c);
	(*count)++;
	*i = *i + len2;
}

int	ft_sizep(char const *s, char c, char d)
{
	int		i;
	char	*str;
	int		size;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != d)
		{
			str = ft_substr(s, i, ft_length(s + i, c, d));
			size = ft_nbrstrs(str, ' ');
			count += size;
			i = i + ft_length(s + i, c, d) - 1;
			free(str);
		}
		else if (s[i] == c)
			increment(&i, s, c, &count);
		else if (s[i] == d)
			increment(&i, s, d, &count);
		i++;
	}
	return (count);
}
