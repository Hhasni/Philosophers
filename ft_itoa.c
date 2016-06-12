/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 13:22:50 by hhasni            #+#    #+#             */
/*   Updated: 2015/07/20 13:22:52 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		ft_int_len(int nb)
{
	int			len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char		*ft_strrevers(char *s)
{
	int			i;
	int			len;
	char		tmp;

	i = 0;
	len = (ft_strlen(s) - 1);
	if (s[i] == '-')
		i++;
	while (i < len)
	{
		tmp = s[len];
		s[len] = s[i];
		s[i] = tmp;
		i++;
		len--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char		*new;
	int			i;
	int			nb;
	int			len;

	i = 0;
	nb = 0;
	len = ft_int_len(n);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (n < 0)
		new[i++] = '-';
	if (n == 0)
		new[i++] = '0';
	while (n != 0)
	{
		if (n < 0)
			nb = -(n % 10) + '0';
		else
			nb = n % 10 + '0';
		n /= 10;
		new[i++] = nb;
	}
	new[i] = '\0';
	return (ft_strrevers(new));
}
