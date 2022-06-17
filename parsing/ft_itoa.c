/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:05:04 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/17 11:17:10 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_init(long *num, int *check, int n)
{
	int		i;
	long	k;

	i = 0;
	*check = 0;
	*num = n;
	k = n;
	if (n < 0)
	{
		*num = -*num;
		k = -k;
		i++;
		*check = 1;
	}
	while (k / 10 > 0)
	{
		k = k / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*tab;
	int		check;

	i = ft_init(&num, &check, n);
	tab = (char *)malloc((i + 2) * sizeof(char));
	if (tab == 0)
		return (NULL);
	tab[i + 1] = '\0';
	while (i >= check)
	{
		tab[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	if (check != 0)
		tab[0] = '-';
	return (tab);
}
