/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:29:05 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:17:02 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstnew(char **cmd, int fd1, int fd2)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == 0)
		return (NULL);
	head->cmd = cmd;
	head->fd_i = fd1;
	head->fd_o = fd2;
	head->next = NULL;
	return (head);
}
