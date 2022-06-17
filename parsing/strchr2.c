/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:56:41 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:15:48 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
	{	
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *) &s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i] + 1);
		i--;
	}
	return (NULL);
}
