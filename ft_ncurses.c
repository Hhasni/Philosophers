/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			ft_manage_exit(bool b)
{
	wrefresh(g_graph.win);
	pthread_mutex_destroy(&g_mutex);
	if (b)
	{
		while (1)
		{
			if (getch() == 27)
				break ;
		}
	}
	endwin();
	exit(EXIT_SUCCESS);
}

static int		ft_setup_graph(void)
{
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	clear();
	srand(time(NULL));
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr, g_graph.gy, g_graph.gx);
	if (!(g_graph.win = newwin(g_graph.gy, g_graph.gx, 1, 0)))
		return (endwin());
	ft_init_pos();
	if (g_graph.gy < 29 && g_graph.gx < 80)
		ft_win_too_small();
	return (0);
}

static void		ft_refresh(void)
{
	clear();
	wrefresh(g_graph.win);
	usleep(16000);
}

static bool		ft_check_time(time_t start_time)
{
	int			current_time;

	current_time = time(NULL);
	if (current_time > start_time + TIMEOUT)
	{
		attrset(COLOR_PAIR(0));
		mvprintw(g_graph.gy - 1,
		g_graph.gx / 2 - (ft_strlen(TIMEOUT_MSG) / 2), TIMEOUT_MSG);
		return (true);
	}
	return (false);
}

void			*ft_ncurses(void)
{
	time_t		start_time;
	int			i;

	start_time = time(NULL);
	ft_setup_graph();
	if (!g_graph.graph)
		ft_display_first();
	while (42)
	{
		i = -1;
		while (++i < NB_PHI)
		{
			ft_display(i);
			if (g_tab_phi[i].life <= 0)
				g_graph.flag = true;
		}
		if (getch() == 27)
			ft_manage_exit(false);
		if (g_graph.flag == true || ft_check_time(start_time))
			ft_manage_exit(true);
		ft_refresh();
	}
	return (NULL);
}
