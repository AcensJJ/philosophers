/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkeat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:23:23 by jacens            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:38 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		freeforks(t_philo *philo)
{
	if (philo->id == philo->stats->nb)
	{
		philo->stats->forks[0] = 1;
		philo->stats->forks[philo->id - 1] = 1;
	}
	else
	{
		philo->stats->forks[philo->id - 1] = 1;
		philo->stats->forks[philo->id] = 1;
	}
	philo->nbforks = 0;
	return (0);
}

int	ft_checkeat(t_philo *philo)
{
	struct timeval	time;
	char	*str;
	char	*str2;

    if (philo->nbforks == 2)
    {
		gettimeofday(&time, NULL);
		philo->lastfood = time.tv_sec * 1000 + time.tv_usec / 1000;
		str = ft_itoa((time.tv_sec - philo->stats->start_time.tv_sec) * 1000 + (time.tv_usec - philo->stats->start_time.tv_usec)/1000);
		str = ft_strjoinrem(str, " ");
		str2 = ft_itoa(philo->id);
		str = ft_strjoinrem(str, str2);
		free(str2);
		str = ft_strjoinrem(str, " is eating\n");
		pthread_mutex_lock(&philo->stats->writemutex);
		write(1, str, ft_strlen(str));
		pthread_mutex_unlock(&philo->stats->writemutex);
		free(str);
		philo->food++;
		if (philo->stats->max_food > 0 && philo->food >= philo->stats->max_food)
		{
			write(1, "philo is satiatied\n", 20);
			exit(EXIT_SUCCESS);
		}
		if (philo->stats->time_to_eat >= philo->stats->time_to_die)
		{
			usleep(philo->stats->time_to_die);
			ft_dies(philo);
		}
		else
			usleep(philo->stats->time_to_eat);
		freeforks(philo);
		ft_sleep(philo);
    }
	else
	{
		ft_checkdeath(philo);
	}
	return (0);
}