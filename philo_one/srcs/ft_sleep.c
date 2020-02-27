/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:23:42 by jacens            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:08 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_sleep(t_philo *philo)
{
	struct timeval	time;
	char	*str;
	char	*str2;

	gettimeofday(&time, NULL);
	str = ft_itoa((time.tv_sec - philo->stats->start_time.tv_sec) * 1000 + (time.tv_usec - philo->stats->start_time.tv_usec)/1000);
	str = ft_strjoinrem(str, " ");
	str2 = ft_itoa(philo->id);
	str = ft_strjoinrem(str, str2);
	free(str2);
	str = ft_strjoinrem(str, " is sleeping\n");
	pthread_mutex_lock(&philo->stats->writemutex);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->stats->writemutex);
	free(str);
	if (philo->stats->time_to_eat + philo->stats->time_to_sleep > philo->stats->time_to_die)
	{
		usleep(philo->stats->time_to_die - philo->stats->time_to_eat);
		ft_dies(philo);
	}
	else
		usleep(philo->stats->time_to_sleep);
	str = ft_itoa((time.tv_sec - philo->stats->start_time.tv_sec) * 1000 + (time.tv_usec - philo->stats->start_time.tv_usec)/1000);
	str = ft_strjoinrem(str, " ");
	str2 = ft_itoa(philo->id);
	str = ft_strjoinrem(str, str2);
	free(str2);
	str = ft_strjoinrem(str, " is thinking\n");
	pthread_mutex_lock(&philo->stats->writemutex);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->stats->writemutex);
	free(str);
	ft_checkfork(philo);
	return (1);
}
