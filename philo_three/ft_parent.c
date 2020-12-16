/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:57:45 by jacens            #+#    #+#             */
/*   Updated: 2020/12/16 11:11:58 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_all_philo_eat(t_philo *philo, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < philo->stats->nb)
		if ((*philos)[i].food < philo->stats->max_food)
			return (0);
	return (1);
}

static int	ft_checkfood(t_philo *philo, t_philo **philos)
{
	if (philo->stats->max_food > 0 && ft_all_philo_eat(philo, philos))
	{
		sem_wait(philo->stats->writemutex);
		if (philo->stats->stop == 1)
		{
			sem_post(philo->stats->writemutex);
			return (1);
		}
		write(1, "philo is satiatied\n", 20);
		philo->stats->stop = 1;
		killforks(philo);
		sem_post(philo->stats->writemutex);
		return (1);
	}
	return (0);
}

int			ft_checkdeath(t_philo *philo, t_philo **philos)
{
	struct timeval	time;
	int				i;

	i = 0;
	gettimeofday(&time, NULL);
	if ((time.tv_sec * 1000 + time.tv_usec / 1000) -
	philo->stats->lastfood[philo->id - 1] > philo->stats->time_to_die / 1000)
	{
		ft_dies(philo);
		killforks(philo);
		sem_post(philo->stats->writemutex);
		return (1);
	}
	return (ft_checkfood(philo, philos));
}

int			ft_dies(t_philo *philo)
{
	char			*str;
	char			*str2;
	struct timeval	time;

	gettimeofday(&time, NULL);
	str = ft_itoa((time.tv_sec - philo->stats->start_time.tv_sec) * 1000 +
		(time.tv_usec - philo->stats->start_time.tv_usec) / 1000);
	str = ft_strjoinrem(str, " ");
	str2 = ft_itoa(philo->id);
	str = ft_strjoinrem(str, str2);
	free(str2);
	str = ft_strjoinrem(str, " died\n");
	sem_wait(philo->stats->writemutex);
	if (philo->stats->stop == 1)
	{
		sem_post(philo->stats->writemutex);
		return (1);
	}
	write(1, str, ft_strlen(str));
	philo->stats->stop = 1;
	free(str);
	return (1);
}

void		*parent(void *data)
{
	t_parent	*papa;
	t_philo		**philo;
	int			i;

	papa = (t_parent *)data;
	philo = (*papa).philo;
	usleep(1000);
	while (1)
	{
		i = -1;
		while (++i < (*philo)[0].stats->nb)
			if (ft_checkdeath(&((*philo)[i]), philo))
				return (NULL);
	}
	return (NULL);
}
