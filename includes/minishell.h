/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:22:56 by mabdelba          #+#    #+#             */
/*   Updated: 2022/06/06 03:56:23 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# define PATH_MAX        4096

typedef struct s_my_env
{
	char		**split;
	char		**tab;
	char		**arr;
	char		**reh;
	char		**her;
	char		**inf;
	char		**outf;
	char		**fcmd;
	char		**cmp;
	char		**var;
	char		**env;
	char const	*s;
	char		*old;
	char		*str;
	char		c;
}			t_char2;

typedef struct s_int1
{
	int		*sort_i;
	int		*sort_o;
	int		*fdr;
	int		*fdo;
	char	c;
	char	d;
	int		size;
	int		dr;
	int		*i;
	int		*j;
	int		*drp;
}			t_int1;

typedef struct s_iptr
{
	int	status;
	int	status1;
}			t_iptr;

typedef struct s_exec
{
	int		i;
	int		nbcmd;
	pid_t	*pid;
	char	**env;
}			t_exec;

typedef struct s_list
{
	char			**cmd;
	int				fd_i;
	int				fd_o;
	struct s_list	*next;
}					t_list;

int		ft_strlen(char	*str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(char **cmd, int fd1, int fd2);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strdup(const char *s1);
void	ft_free(char **str);
void	collect_data(t_char2 ch, t_list **data, t_iptr *ptr, int **drp);
void	print0(t_list **data);
char	*ft_strtrim(char *s1, char *set);
int		ft_strchr(char *s, char c);
int		is_string(char *str);
char	**ft_splitp(char const *s, char c, char d, int **drp);
char	**checkinout(char **str, char c, char d, int *drp);
int		*openfiles(char **str, int inout, int *status);
void	newline(int sig);
char	**reduce(char **str);
int		sizeinout(char *str, char c, char d);
char	**heredoc(char **str, char c, int *drp);
void	error1(void);
int		ft_strcmp(const char *s1, const char *s2);
int		countinout(char **str, char c, int *drp);
char	*ft_strchr2(const char *s, int c);
char	*ft_strjoinc(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
int		ft_leng(char **str);
char	**reduce(char **str);
char	**reduce1(char **str);
int		ft_isdigit(int c);
int		ft_isalnum(int numTest);
int		ft_strchrp(char *s);
void	ft_cleaning(char **str, int *drp);
int		*sort_infil(t_char2 strct, char **str, int *drp, char c);
int		*ft_paste(char **s1, char **s2, int *status);
char	*ft_first(char *str);
char	*get_str(t_char2 s, int *count, char **var, int *drp);
char	**finale_cmd(char **old, char **env, int *drp, int status);
int		count_dollars(char **str, char c, int *drp);
char	**variables(char **str, int *drp);
char	*getvar(char **env, char *str);
char	**compens_var(char **str, char **env, int status, int *drp);
int		ft_nbrstrs(const char *s, char c);
size_t	ft_length(const char *s, char c, char d);
size_t	ft_length2(const char *s, char c);
int		ft_sizep(char const *s, char c, char d);
size_t	ft_strlen_ex(const char *s);
char	**ft_split(char const *s, char c);
int		ft_gettheworld(const char *s, char c);
char	*ft_strjoin_ex(char const *s1, char const *s2);
void	exec(char **av, int poscmd, char **path, char **env);
int		ft_numofsplit(const char *s, char spl);
int		checkpath(char *path);
void	checkexec(char *path, int *status);
void	checkrdwr(char *file, int rdwr, int fd, int *status);
char	*getpath(char **env);
void	checkproblem(int p[2], pid_t *pid);
void	duplicate(int fd1, int fd2);
int		ft_strcmp_ex(char *s1, char *s2);
int		heredocpipe(char *limitter, int status);
int		ft_numofsplit(const char *s, char spl);
char	*get_next_line(int fd);
void	newpipe2(t_list **data, int nbcmd, char **env, int *status1);
char	*ft_strstr(char *str, char *to_find);
char	*ft_itoa(int n);
int		ft_parsing(char *buff);
int		last_element(int *tab, int flg);
int		builtings(t_exec ex, int outfile, t_list **data);
void	exec2(t_exec ex, char **av, char **path, int *status);
void	opn(t_list **data, char **env);
int		*outfiles(int **outfile);
void	rehdocpipe(int outfile);
int		nb_cmd(t_list *data);
int		*tabout(t_list *data);
int		*tabin(t_list *data);
int		sizetab(int *tab);
int		*outfiles(int **outfile);
void	ft_echo(char	**str);
void	ft_env(char **env);
char	**ft_unset(char **env, char **str);
void	ft_cd(char	*str);
char	**ft_export(char **str, char **env);
void	ft_pwd(void);
char	**myenv(char **env);
void	error3(void);
#endif