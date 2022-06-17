/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 03:39:49 by aelabid           #+#    #+#             */
/*   Updated: 2022/05/30 12:36:25 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_next_line(int fd)
{
	static char	*buffer_reminder;
	char		buff[1];
	char		line[1000000];
	int			i;
	int			n;

	i = 0;
	buffer_reminder = 0;
	if (fd < 0)
		return (NULL);
	line[0] = 0;
	n = read(fd, buff, 1);
	while (n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
