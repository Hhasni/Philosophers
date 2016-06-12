/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		ft_display_my_id(int i)
{
	if (g_graph.id)
	{
		mvprintw(g_graph.pos[i][1] - 1, g_graph.pos[i][0],
		ft_itoa(g_tab_phi[i].id));
	}
}

static void		ft_display_my_state(int i)
{
	if (g_graph.state)
	{
		mvprintw(g_graph.pos[i][1] - 1, g_graph.pos[i][0]
		+ ft_strlen(g_graph.tab[i]) - 1, &g_tab_phi[i].state);
	}
}

static void		ft_display_my_life(int i)
{
	int			j;

	j = 0;
	if (g_graph.color && g_tab_phi[i].life <= 3)
		wattron(g_graph.win, COLOR_PAIR(1));
	while (j < g_tab_phi[i].life)
	{
		mvwaddch(g_graph.win, g_graph.pos[i][1], g_graph.pos[i][0] + j, '|');
		j++;
	}
	if (g_tab_phi[i].life <= 0)
	{
		ft_display_death(g_graph.pos[i][1] + 1,
		g_graph.pos[i][0] + 2, 0,
		(g_graph.gx / 2) - (ft_strlen("Press Esc to quit") / 2));
	}
}

static void		ft_display_my_number(int i)
{
	char		*new_string;

	if (g_graph.number)
	{
		new_string = ft_itoa(g_tab_phi[i].life);
		mvprintw(g_graph.pos[i][1] + 1,
		g_graph.pos[i][0] + MAX_LIFE + 2, new_string);
	}
}

void			ft_manage_display_graph(int i)
{
	mvprintw(g_graph.pos[i][1], g_graph.pos[i][0], g_graph.tab[i]);
	ft_display_my_id(i);
	ft_display_my_state(i);
	ft_display_my_life(i);
	ft_display_my_number(i);
	if (g_tab_phi[i].hashi == 1)
	{
		attrset(COLOR_PAIR(0));
		mvprintw(g_graph.pos[i][1], g_graph.pos[i][0] - 5, "____");
	}
}
