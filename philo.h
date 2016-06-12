/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <curses.h>

# define MAX_LIFE	10
# define EAT_T		2
# define REST_T		3
# define THINK_T	3
# define TIMEOUT	9

/*
** DO NOT CHANGE
*/
# define NB_PHI		7

/*
** DO NOT CHANGE
*/
# define PADDING	15
# define TIMEOUT_MSG "Now, it is time... To DAAAAAAAANCE!!!"

typedef struct		s_graph
{
	WINDOW			*win;
	char			*tab[NB_PHI];
	int				gx;
	int				gy;
	bool			flag;
	int				id;
	int				name;
	int				number;
	int				color;
	int				state;
	int				pos[NB_PHI][2];
	int				graph;
}					t_graph;

typedef struct		s_phi
{
	int				id;
	char			hashi;
	pthread_t		thread;
	char			state;
	int				life;
}					t_phi;

t_phi				g_tab_phi[NB_PHI];
pthread_mutex_t		g_mutex;
t_graph				g_graph;

int					ft_strlen(char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *str);
char				*ft_itoa(int n);
void				ft_putendl(char *s);

void				ft_init_pos(void);
void				*ft_ncurses();
void				*ft_life(void *src);
void				ft_display_first(void);
void				ft_display(int i);
void				ft_display_death(int pos1, int pos2, int pos3, int pos4);
void				ft_manage_display_graph(int i);
void				ft_manage_display_normal(int i);
void				ft_win_too_small(void);
void				ft_manage_exit(bool b);

#endif
