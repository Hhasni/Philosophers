/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_extend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			ft_display_first(void)
{
	int			i;

	i = 0;
	while (i++ < NB_PHI)
		mvprintw(i + 1, 0, g_graph.tab[g_tab_phi[i].id]);
	wrefresh(g_graph.win);
}

void			ft_init_pos(void)
{
	g_graph.pos[0][0] = (g_graph.gx / 2) - (ft_strlen(g_graph.tab[0]) / 2);
	g_graph.pos[0][1] = g_graph.gy / 10;
	g_graph.pos[1][0] = (g_graph.gx / 2) - (g_graph.gx / 4)
	- (ft_strlen(g_graph.tab[1]) / 2);
	g_graph.pos[1][1] = g_graph.gy / 5;
	g_graph.pos[2][0] = (g_graph.gx / 2) - (g_graph.gx / 3)
	- (ft_strlen(g_graph.tab[2]) / 2);
	g_graph.pos[2][1] = g_graph.gy / 2;
	g_graph.pos[3][0] = (g_graph.gx / 2) - (g_graph.gx / 4)
	- (ft_strlen(g_graph.tab[3]) / 2);
	g_graph.pos[3][1] = g_graph.gy - (g_graph.gy / 5);
	g_graph.pos[4][0] = (g_graph.gx / 2) + (g_graph.gx / 4)
	- (ft_strlen(g_graph.tab[4]) / 2);
	g_graph.pos[4][1] = g_graph.gy - (g_graph.gy / 5) + 1;
	g_graph.pos[5][0] = (g_graph.gx / 2) + (g_graph.gx / 3)
	- (ft_strlen(g_graph.tab[5]) / 2);
	g_graph.pos[5][1] = g_graph.gy / 2 + 1;
	g_graph.pos[6][0] = (g_graph.gx / 2) + (g_graph.gx / 4)
	- (ft_strlen(g_graph.tab[6]) / 2);
	g_graph.pos[6][1] = g_graph.gy / 5 + 1;
}

void			ft_display_death(int pos1, int pos2, int pos3, int pos4)
{
	mvprintw(pos1, pos2, "DEAD");
	attrset(COLOR_PAIR(0));
	mvprintw(pos3, pos4, "Press Esc to quit");
}

void			ft_display(int i)
{
	int			type;

	type = 0;
	if (g_graph.color)
	{
		if (g_tab_phi[i].state == 'R')
			type = 3;
		if (g_tab_phi[i].state == 'E')
			type = 2;
		if (g_tab_phi[i].state == 'T')
			type = 4;
		attrset(COLOR_PAIR(type));
		wattron(g_graph.win, COLOR_PAIR(type));
	}
	if (g_graph.graph)
		ft_manage_display_graph(i);
	else
		ft_manage_display_normal(i);
}

void			ft_win_too_small(void)
{
	int			tmpy;
	int			tmpx;

	tmpx = 0;
	tmpy = 0;
	while (getch() != 27)
	{
		getmaxyx(stdscr, tmpy, tmpx);
		mvprintw(g_graph.gy / 2, g_graph.gx / 2
		- (ft_strlen("Win Too Small") / 2), "Win Too Small");
		wrefresh(g_graph.win);
	}
	ft_manage_exit(false);
}
