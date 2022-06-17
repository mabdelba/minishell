/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:56:08 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/01 19:40:38 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*cpy;

// 	cpy = (char *)malloc((ft_strlen_ex(s1) + 1) * sizeof(char));
// 	if (cpy == 0)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		cpy[i] = s1[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

char	*ft_strjoin_ex(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	j = 0;
	i = -1;
	str = (char *)malloc((ft_strlen_ex(s2)
				+ ft_strlen_ex(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j++];
		i++;
	}
	str[i] = '\0';
	return (str);
}
