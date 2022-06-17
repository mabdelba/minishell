/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_data_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:17:50 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:17:36 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*ft_paste(char **s1, char **s2, int *status)
{
	int		*p1;
	int		*p2;
	int		i;
	int		z;
	int		*tab;

	tab = malloc((ft_leng(s1) + ft_leng(s2) + 1) * sizeof(int));
	if (!tab)
		exit(EXIT_FAILURE);
	p1 = openfiles(s1, 1, status);
	p2 = openfiles(s2, 2, status);
	i = 0;
	z = 0;
	while (s1[i])
		tab[z++] = p1[i++];
	i = 0;
	while (s2[i])
		tab[z++] = p2[i++];
	tab[z] = -1;
	return (tab);
}

int	last_element(int *tab, int flg)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
		i++;
	if (i > 0)
		return (tab[i - 1]);
	else
		return (flg);
}

int	ft_strchrp(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{	
		if (s[i] == '>' || s[i] == '<')
			return (1);
		i++;
	}
	return (0);
}
