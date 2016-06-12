/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			ft_join_phi(void)
{
	int				i;
	int				ret;

	i = 0;
	while (i < NB_PHI)
	{
		ret = pthread_join(g_tab_phi[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&g_mutex);
}

static void			ft_init_graph(void)
{
	g_graph.tab[0] = "Galilee";
	g_graph.tab[1] = "Newton";
	g_graph.tab[2] = "Archimede";
	g_graph.tab[3] = "Einstein";
	g_graph.tab[4] = "Giordano Bruno";
	g_graph.tab[5] = "Pythagore";
	g_graph.tab[6] = "Copernic";
	g_graph.flag = false;
	g_graph.id = 0;
	g_graph.number = 0;
	g_graph.color = 0;
	g_graph.state = 0;
	g_graph.graph = 0;
}

static void			ft_init_phi(void)
{
	int				i;

	i = 0;
	if (NB_PHI != 7)
	{
		ft_putendl("\033[1;31mFUCK YOU <3\033[0m");
		exit(-1);
	}
	pthread_mutex_init(&(g_mutex), NULL);
	while (i < NB_PHI)
	{
		g_tab_phi[i].id = i;
		g_tab_phi[i].hashi = 1;
		g_tab_phi[i].state = 'I';
		g_tab_phi[i].life = MAX_LIFE;
		pthread_create(&(g_tab_phi[i].thread), NULL, ft_life, &(g_tab_phi[i]));
		i++;
	}
}

static void			ft_check_bonus(int ac, char **av)
{
	int				i;

	i = 0;
	ft_init_graph();
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-id") || !ft_strcmp(av[i], "-full"))
			g_graph.id = 1;
		if (!ft_strcmp(av[i], "-color") || !ft_strcmp(av[i], "-full"))
			g_graph.color = 1;
		if (!ft_strcmp(av[i], "-number") || !ft_strcmp(av[i], "-full"))
			g_graph.number = ((g_graph.id * 1) + PADDING + MAX_LIFE + 5);
		if (!ft_strcmp(av[i], "-state") || !ft_strcmp(av[i], "-full"))
			g_graph.state = (((g_graph.id * 1) + PADDING + MAX_LIFE + 5) + 5);
		if (!ft_strcmp(av[i], "-help") || !ft_strcmp(av[i], "-full"))
			g_graph.id = 1;
		if (!ft_strcmp(av[i], "-graph"))
			g_graph.graph = 1;
		i++;
	}
}

int					main(int ac, char **av)
{
	pthread_t		thread_graphique;
	int				i;

	i = 0;
	if (ac >= 2)
	{
		if (!ft_strcmp(av[1], "-help") || !ft_strcmp(av[1], "-h"))
		{
			ft_putendl("./philo [-ARG]");
			ft_putendl("-id \tto have philosophers id");
			ft_putendl("-color \tto have color");
			ft_putendl("-number to have philosophers life number");
			ft_putendl("-state \tto have philosophers state");
			ft_putendl("-full \tto have it all");
			ft_putendl("-graph \tto use awesome graphical version");
			return (0);
		}
	}
	ft_init_phi();
	ft_check_bonus(ac, av);
	pthread_create(&thread_graphique, NULL, ft_ncurses, NULL);
	ft_join_phi();
	return (0);
}
