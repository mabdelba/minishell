/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:47:03 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/01 19:40:53 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen_ex(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*nstr;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (len >= ft_strlen_ex(s))
// 		len = ft_strlen_ex(s);
// 	if (ft_strlen_ex(s) <= start)
// 		return (ft_strdup(""));
// 	nstr = malloc((len + 1) * sizeof(char));
// 	if (nstr == 0)
// 		return (0);
// 	while (i < len && s[i] != '\0')
// 	{
// 		nstr[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	nstr[i] = '\0';
// 	return (nstr);
// }

int	ft_strcmp_ex(char *s1, char *s2)
{
	unsigned char	*s1_xd;
	unsigned char	*s2_xd;
	size_t			i;

	i = 0;
	s1_xd = (unsigned char *) s1;
	s2_xd = (unsigned char *) s2;
	while (s1_xd[i] && s1_xd[i] == s2_xd[i])
		i++;
	return (s1_xd[i] - s2_xd[i]);
}

int	ft_numofsplit(const char *s, char spl)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == spl)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != spl)
			i++;
	}
	return (k);
}
