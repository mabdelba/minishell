/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:46:01 by aelabid           #+#    #+#             */
/*   Updated: 2022/05/25 19:58:04 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

int	nb_cmd(t_list *data)
{
	int	i;

	i = 0;
	while (data != NULL)
	{
		data = (*data).next;
		i++;
	}
	return (i);
}
