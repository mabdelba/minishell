/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:33:45 by aelabid           #+#    #+#             */
/*   Updated: 2022/06/06 03:51:35 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int numTest)
{
	if (((numTest >= 'A' && numTest <= 'Z' )
			|| (numTest >= 'a' && numTest <= 'z'))
		|| (numTest >= '0' && numTest <= '9'))
		return (1);
	return (0);
}
