/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:16:00 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:18 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_leng(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned char		*casts1;
	unsigned char		*casts2;

	i = 0;
	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	while (casts1[i] && casts2[i] && casts1[i] == casts2[i])
		i++;
	if (casts1[i] > casts2[i])
		return (1);
	if (casts1[i] < casts2[i])
		return (-1);
	return (0);
}
