/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:18:21 by youssama          #+#    #+#             */
/*   Updated: 2022/04/05 02:29:50 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct t_stab
{
	int	*tab_a;
	int	*tab_b;
	int	top_a;
	int	top_b;
}t_stab;

void		sb_b(int *t, int top);
void		sa_b(int *t, int top);
void		ss_b(int *t_a, int top_a, int *t_b, int top_b);
void		pb_b(int *t_a, int *top_a, int *t_b, int *top_b);
void		pa_b(int *t_a, int *top_a, int *t_b, int *top_b);
void		ra_b(int *t, int top);
void		rb_b(int *t, int top);
void		rr_b(int *t_a, int top_a, int *t_b, int top_b);
void		rra_b(int *t, int top);
void		rrb_b(int *t, int top);
void		rrr_b(int *t_a, int top_a, int *t_b, int top_b);
int			ft_strcmp(char *s1, char *s2);
void		quit_b(t_stab *var, int c, char **v, char *j);
void		test_j(char *j, t_stab *va, char **v);
int			check(int *t, int top);
char		*get_next_line(int fd);
long long	ft_atoi(char *str, t_stab *var, char **v);
int			check(int *t, int top);
void		ft_putstr(char *s);
int			check_repeat(int *t, int top);
int			check_arg(char **v);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		**ft_split(char *s, char c, char **tmp);
char		**fret(char **p);
int			check_space(char **v);

#endif
