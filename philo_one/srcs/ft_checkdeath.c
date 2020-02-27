/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdeath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:23:19 by jacens            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:08 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_checkdeath(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if ((time.tv_sec * 1000 + time.tv_usec/1000) - philo->lastfood > philo->stats->time_to_die / 1000)
		ft_dies(philo);
	return (0);
}
