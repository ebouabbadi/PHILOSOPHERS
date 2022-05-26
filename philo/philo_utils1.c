/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:16:08 by ebouabba          #+#    #+#             */
/*   Updated: 2022/05/26 19:32:07 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_of_philo)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->print);
	free(info->philos);
	free(info->forks);
}

int	check_eating(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->info->nbr_of_must_eat < 0)
		return (1);
	while (++i < philo->info->nbr_of_philo)
	{
		if (philo[i].count_eat != philo[i].num_eat)
			return (1);
	}
	return (0);
}

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print);
	printf("%ld ms %d %s\n", get_time() - philo->info->time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->info->print);
}

void	ft_usleep(long ms)
{
	long	end;

	end = get_time() + ms;
	while (get_time() < end)
		usleep(50);
}
