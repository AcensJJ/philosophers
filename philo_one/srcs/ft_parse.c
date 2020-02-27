/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:23:37 by jacens            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:08 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_check(int ac, t_file *stats)
{
	if (stats->nb < 1)
	{
		write(1, "Need at least one philosopher\n", 30);
		return (0);
	}
	if (stats->time_to_die <= 0)
	{
		write(1, "philosophers start dead\n", 25);
		return (0);
	}
	if (stats->time_to_eat < 0)
	{
		write(1, "negative time_to_eat\n", 21);
		return (0);
	}
	if (stats->time_to_sleep < 0)
	{
		write(1, "negative time_to_sleep\n", 23);
		return (0);
	}
	if (ac == 6 && stats->max_food < 1)
	{
		write(1, "philosophers start satiated\n", 28);
		return (0);
	}
	return (1);
}

int		ft_parse(int ac, char **av, t_file *stats)
{
	int i;

	stats->option = 0;
	stats->nb = ft_atoi(av[1]);
	stats->time_to_die = (long int)ft_atoi(av[2]) * 1000;
	stats->time_to_eat = ft_atoi(av[3]) * 1000;
	stats->time_to_sleep = ft_atoi(av[4]) * 1000;
	gettimeofday(&stats->start_time, NULL);
	stats->lstart = (stats->start_time.tv_sec) * 1000 + (stats->start_time.tv_usec) / 1000;
	pthread_mutex_init(&stats->forkmutex, NULL);
	pthread_mutex_init(&stats->writemutex, NULL);
	if (ac == 6)
	{
		stats->max_food = ft_atoi(av[5]);
		if (stats->max_food < 1)
		{
			write(1, "philosophers start satiated\n", 28);
			return (0);
		}
	}
	else
		stats->max_food = -1;
	stats->forks = malloc(sizeof(int) * stats->nb);
	i = 0;
	while (i < stats->nb)
	{
		stats->forks[i] = 1;
		i++;
	}
	return(ft_check(ac, stats));
}