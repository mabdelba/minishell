/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:46:18 by aelabid           #+#    #+#             */
/*   Updated: 2022/05/30 12:28:39 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	leng;
	int	i;
	int	j;
	int	k;
	int	first_i;

	leng = ft_strlen_ex(to_find);
	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0' )
	{
		first_i = i;
		j = 0;
		k = i;
		while (str[k] == to_find[j] && to_find[j] != '\0')
		{
			k++;
			j++;
		}
		if (leng == j)
			return (&str[first_i]);
		i++;
	}
	return (0);
}

char	*getpath(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH") != 0)
			return (ft_split(env[i], '=')[1]);
		i++;
	}
	write(2, "PATH not found", 15);
	exit(1);
}
