/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		ft_display_bonus(int i)
{
	char		*new_string;

	if (g_graph.number)
	{
		new_string = ft_itoa(g_tab_phi[i].life);
		mvprintw(i + 1 + (i * 1), g_graph.number, new_string);
	}
	if (g_graph.state)
		mvprintw(i + 1 + (i * 1), g_graph.state, &g_tab_phi[i].state);
}

static void		ft_display_hashi(int i)
{
	if (g_tab_phi[i].hashi == 1)
	{
		attrset(COLOR_PAIR(0));
		mvprintw(i + (i * 1), 1, "_______");
	}
}

static void		ft_display_id_name_life(int i)
{
	int			j;

	j = 0;
	if (g_graph.color && g_tab_phi[i].life <= 3)
		wattron(g_graph.win, COLOR_PAIR(1));
	if (g_graph.id)
		mvprintw(i + 1 + (i * 1), g_graph.id, ft_itoa(g_tab_phi[i].id));
	mvprintw(i + 1 + (i * 1), (g_graph.id * 3), g_graph.tab[i]);
	while (j < g_tab_phi[i].life)
	{
		mvwaddch(g_graph.win, i + (i * 1), g_graph.id + 3 + j + PADDING, '|');
		j++;
	}
}

void			ft_manage_display_normal(int i)
{
	ft_display_id_name_life(i);
	ft_display_bonus(i);
	ft_display_hashi(i);
	if (g_tab_phi[i].life <= 0)
	{
		ft_display_death(i + 1 + (i * 1), (MAX_LIFE / 2)
		+ PADDING - 2, NB_PHI + NB_PHI + 2, 5);
	}
}
