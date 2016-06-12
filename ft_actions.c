/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void			ft_eat(t_phi *src)
{
	int				i;

	i = 0;
	src->state = 'E';
	src->life = MAX_LIFE;
	g_tab_phi[src->id].hashi = 0;
	g_tab_phi[(src->id + 1) % NB_PHI].hashi = 0;
	pthread_mutex_unlock(&g_mutex);
	while (i < EAT_T)
	{
		src->life = MAX_LIFE;
		sleep(1);
		i++;
	}
	pthread_mutex_lock(&g_mutex);
	g_tab_phi[src->id].hashi = 1;
	g_tab_phi[(src->id + 1) % NB_PHI].hashi = 1;
	src->state = 'R';
}

static void			ft_think(t_phi *src)
{
	int				i;

	i = 0;
	src->state = 'T';
	if (g_tab_phi[src->id].hashi == 1)
		g_tab_phi[src->id].hashi = -1;
	else if (g_tab_phi[(src->id + 1) % NB_PHI].hashi == 1)
		g_tab_phi[(src->id + 1) % NB_PHI].hashi = -1;
	pthread_mutex_unlock(&g_mutex);
	while (i < THINK_T)
	{
		src->life -= 1;
		sleep(1);
		i++;
	}
	if (g_tab_phi[src->id].hashi == -1)
		g_tab_phi[src->id].hashi = 1;
	else if (g_tab_phi[(src->id + 1) % NB_PHI].hashi == -1)
		g_tab_phi[(src->id + 1) % NB_PHI].hashi = 1;
	pthread_mutex_lock(&g_mutex);
	src->state = 'R';
}

static void			ft_rest(t_phi *src)
{
	int				i;

	i = 0;
	src->state = 'R';
	pthread_mutex_unlock(&g_mutex);
	while (i < REST_T)
	{
		src->life -= 1;
		sleep(1);
		i++;
	}
	pthread_mutex_lock(&g_mutex);
}

static void			ft_manage_actions(t_phi *philo)
{
	char			r;
	char			l;

	l = g_tab_phi[philo->id].hashi;
	r = g_tab_phi[(philo->id + 1) % NB_PHI].hashi;
	if (r && l)
	{
		ft_eat(philo);
		ft_rest(philo);
	}
	else if (r == 1 || l == 1)
	{
		ft_think(philo);
	}
	else
		ft_rest(philo);
}

void				*ft_life(void *src)
{
	t_phi			*philo;

	philo = (t_phi *)src;
	while (42)
	{
		sleep(1);
		pthread_mutex_lock(&g_mutex);
		if (philo->life <= 0)
		{
			philo->state = 'D';
			pthread_mutex_lock(&g_mutex);
			return (NULL);
		}
		ft_manage_actions(philo);
		philo->life -= 1;
		pthread_mutex_unlock(&g_mutex);
	}
}
