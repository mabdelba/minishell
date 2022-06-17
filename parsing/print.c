/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:21 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:16:04 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void print0(t_list **data)
// {
//     int i = 0;
//     char **args1;
//     t_infile *args2;
//     int **args3;
//     int *sort;
//     int j;

//     args1 = (*data)->cmd;
//     args2 = (*data)->infile;
//     args3 = (*data)->outfile;
//     sort = (*data)->sort;
//     printf("cmd : ");
//     while(args1[i])
//     {
//         printf("{%s} ", args1[i]);
//         i++;
//     }
//     printf("\n");
//     i = 0;
//     printf("infiles:\t");
//     j = 0;
//     while (args2->in[j] != -1)
//     {
//         printf("in = {%d} ", args2->in[j]);
//         j++;
//     }
//     printf("\nheredoc =");
//     j = 0;
//     while (args2->hered[j] != NULL)
//     {
//         printf(" %s ", args2->hered[j]);
//         j++;
//     }
//     i = 0;
//     printf("\noutfile = ");
//     while (i < 2)
//     {
//         j = 0;
//         while (args3[i][j] != -1)
//         {
//             printf("{%d} ", args3[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
//      i = 0;
//     printf("\n");
// 	while (sort[i] != -1)
// 	{
// 		printf("[%d]", sort[i]);
// 		i++;
// 	}
// }
