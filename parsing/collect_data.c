/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:37:25 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/17 11:14:31 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	siout(t_char2 *s, t_int1 *p, int **drp, int i)
{
	s->tab = ft_splitp(s->split[i], '"', '\'', drp);
	s->inf = checkinout(s->tab, '<', '>', *drp);
	s->outf = checkinout(s->tab, '>', '<', *drp);
	s->her = heredoc(s->tab, '<', *drp);
	s->reh = heredoc(s->tab, '>', *drp);
	p->sort_i = sort_infil(*s, s->tab, *drp, '<');
}

void	jstopen(t_int1 *p, t_iptr *ptr, t_char2 *s, int *fd_i)
{
	if (last_element(p->sort_i, 0))
	{
		p->fdr = openfiles(s->her, 3, &(ptr->status1));
		p->fdo = openfiles(s->inf, 0, &(ptr->status1));
		*fd_i = last_element(p->fdr, 0);
	}
	else
	{
		p->fdr = openfiles(s->inf, 0, &(ptr->status1));
		p->fdo = openfiles(s->her, 3, &(ptr->status1));
		*fd_i = last_element(p->fdr, 0);
	}
	free(p->sort_i);
	free(p->fdr);
	free(p->fdo);
}

void	jstopen2(t_int1 *p, t_iptr *ptr, t_char2 *s, int *fd_o)
{
	if (last_element(p->sort_o, 1))
	{
		p->fdr = openfiles(s->reh, 2, &(ptr->status1));
		p->fdo = openfiles(s->outf, 1, &(ptr->status1));
		*fd_o = last_element(p->fdr, 1);
	}
	else
	{
		p->fdr = openfiles(s->reh, 2, &(ptr->status1));
		p->fdo = openfiles(s->outf, 1, &(ptr->status1));
		*fd_o = last_element(p->fdo, 1);
	}
	free(p->sort_o);
	free(p->fdr);
	free(p->fdo);
}

void	ft_free2(t_char2 *s)
{
	ft_free(s->inf);
	ft_free(s->outf);
	ft_free(s->her);
	ft_free(s->reh);
	ft_free(s->arr);
	ft_free(s->tab);
}

void	collect_data(t_char2 ch, t_list **data, t_iptr *ptr, int **drp)
{
	t_char2		s;
	t_int1		p;
	int			i;
	int			fd_i;
	int			fd_o;

	ptr->status1 = 0;
	s.split = ft_split(ch.str, '|');
	i = 0;
	while (s.split[i])
	{
		siout(&s, &p, drp, i);
		jstopen(&p, ptr, &s, &fd_i);
		p.sort_o = sort_infil(s, s.tab, *drp, '>');
		jstopen2(&p, ptr, &s, &fd_o);
		ft_cleaning(s.tab, *drp);
		s.arr = reduce(s.tab);
		s.fcmd = finale_cmd(s.arr, ch.env, *drp, ptr->status);
		ft_lstadd_back(data, ft_lstnew(s.fcmd, fd_i, fd_o));
		ft_free2(&s);
		free(*drp);
		i++;
	}
	ft_free(s.split);
}

// void	collect_data(t_char2 ch,  t_list  **data, t_iptr *ptr, int **drp)
// {
// 	t_char2		s;
// 	t_int1		p;
// 	int			i;
// 	int			fd_i;
// 	int			fd_o;

// 	ptr->status1 = 0;
// 	s.split = ft_split(ch.str, '|');
// 	i = 0;
// 	while (s.split[i])
// 	{
// 		// siout(&s, &p, drp, i);
// 		s.tab = ft_splitp(s.split[i], '"', '\'', drp);
// 		s.inf = checkinout(s.tab, '<', '>', *drp);
// 		s.outf = checkinout(s.tab, '>', '<', *drp);
// 		s.her = heredoc(s.tab, '<', *drp);
// 		s.reh = heredoc(s.tab, '>', *drp);
// 		p.sort_i = sort_infil(s, s.tab, *drp, '<');
// 		if (last_element(p.sort_i, 0))
// 		{
// 			p.fdr = openfiles(s.her, 3, &(ptr->status1));
// 			p.fdo = openfiles(s.inf, 0, &(ptr->status1));
// 			fd_i = last_element(p.fdr, 0);
// 		}
// 		else
// 		{
// 			p.fdr = openfiles(s.inf, 0, &(ptr->status1));
// 			p.fdo = openfiles(s.her, 3, &(ptr->status1));
// 			fd_i = last_element(p.fdr, 0);
// 		}
// 		free(p.sort_i);
// 		free(p.fdr);
// 		free(p.fdo);
// 		p.sort_o = sort_infil(s, s.tab, *drp, '>');
// 		if (last_element(p.sort_o, 1))
// 		{
// 			p.fdr = openfiles(s.reh, 2, &(ptr->status1));
// 			p.fdo = openfiles(s.outf, 1, &(ptr->status1));
// 			fd_o = last_element(p.fdr, 1);
// 		}
// 		else
// 		{
// 			p.fdr = openfiles(s.reh, 2, &(ptr->status1));
// 			p.fdo = openfiles(s.outf, 1, &(ptr->status1));
// 			fd_o = last_element(p.fdo, 1);
// 		}
// 		free(p.sort_o);
// 		free(p.fdr);
// 		free(p.fdo);
// 		ft_cleaning(s.tab, *drp);
// 		s.arr = reduce(s.tab);
// 		s.fcmd = finale_cmd(s.arr, ch.env, *drp, ptr->status);
// 		ft_lstadd_back(data, ft_lstnew(s.fcmd, fd_i, fd_o));
// 		ft_free(s.inf);
// 		ft_free(s.outf);
// 		ft_free(s.her);
// 		ft_free(s.reh);
// 		ft_free(s.arr);
// 		ft_free(s.tab);
// 		free(*drp);
// 		i++;
// 	}
// 	ft_free(s.split);
// }
