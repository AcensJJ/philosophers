/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:23:32 by jacens            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:08 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_dies(t_philo *philo)
{
	char *str;
	char *str2;
	struct timeval	time;

	gettimeofday(&time, NULL);
	str = ft_itoa((time.tv_sec - philo->stats->start_time.tv_sec) * 1000 + (time.tv_usec - philo->stats->start_time.tv_usec)/1000);
	str = ft_strjoinrem(str, " ");
	str2 = ft_itoa(philo->id);
	str = ft_strjoinrem(str, str2);
	free(str2);
	str = ft_strjoinrem(str, " died\n");
	pthread_mutex_lock(&philo->stats->writemutex);
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&philo->stats->writemutex);
	free(str);
	exit(0);
}