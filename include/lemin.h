/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:28:59 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 15:30:16 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 42

typedef	struct		s_list
{
	int				**tab;
	char			**name;
	char			**all;
	int				**path;
	int				**bestpath;
	int				**display;
	int				nbrant;
	int				pathlen;
	int				nbrroom;
	int				tablen;
	int				pathmin;
	int				start;
	int				end;
}					t_list;

int					main(void);

int					ft_strcmp(char *s1, char *s2);
int					findstr(char *str, t_list *new, int *i);
int					takeid(char *line, t_list *new, int id);
char				*ft_strchr(char *str, char a);
char				*strcpyspace(char *line);

int					removepath(t_list *new);
int					tabcpy2(int *new, int *tab);
int					isgoodpath(t_list *new, int *tab);

int					launchread(t_list *new);
int					addline(char *str, t_list *new);
int					getantnbr(t_list *new);
int					error(void);

int					display(t_list *new);
int					displayvalue(t_list *new);
int					setnewvalue(t_list *new);
int					sendant(t_list *new);
int					newroom(t_list *new, int x);

int					addroom(char *line, t_list *lst);
int					addtube(char *line, t_list *lst);
int					isroomline(char *line);
int					istubeline(char *line, t_list *new);
int					tabtabchr(int *tab, int *tab2);

t_list				*initlist(void);
int					freeall(t_list *lst);
int					freepars(t_list *new);
int					init_bestpath(t_list *new, int x, int y);
int					fillpathlen(t_list *new);

int					ft_strlen(char *a);
int					ft_putstr(char *a);
int					ft_putnbr(int nb);
int					ft_putchar(char a);
int					initint(int *i, int *j);

int					ft_strlenchr(char *buffer, int a);
int					saveline(char *buffer, char **line, char **buf);
char				*ft_strjoin2(char *str, char *str2);
int					addbuff(char **buffer, int const fd, int *ret);
int					get_next_line(int const fd, char **line);

int					takeallpath(t_list *new, int actual, int x);
int					tabchr(int *tab, int x);
int					newpath(t_list *new, int x, int toadd);
int					tabcpy(t_list *new);

int					keepbestpath(t_list *new);
int					takeotherpath(t_list *new, int x);
int					sendants(t_list *new);
int					takemin(t_list *new);
int					canaddpath(t_list *new, int x);

int					addtoall(t_list *new, char *s);
int					checkone(t_list *new);
int					printonepath(t_list *new);

int					displaypars(t_list *new);
#endif
