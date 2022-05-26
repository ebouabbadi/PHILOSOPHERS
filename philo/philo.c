/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:16:10 by ebouabba          #+#    #+#             */
/*   Updated: 2022/05/26 19:40:10 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(40);
	while (1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->id]);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->id_next]);
		print_message(philo, "has taken a fork");
		philo->last_eat = get_time();
		print_message(philo, "is eating");
		if (philo->count_eat != philo->num_eat
			&& philo->info->nbr_of_must_eat > 0)
				philo->count_eat++;
		ft_usleep(philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->id]);
		pthread_mutex_unlock(&philo->info->forks[philo->id_next]);
		print_message(philo, "is sleeping");
		ft_usleep(philo->info->time_to_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}

void	*monitor(void	*arg)
{
	t_info	*info;
	int		i;

	info = arg;
	while (1)
	{
		if (check_eating(info->philos) == 0)
			return (NULL);
		i = -1;
		while (++i < info->nbr_of_philo)
		{
			if (get_time() - info->philos[i].last_eat >= info->time_to_die)
			{
				print_message(info->philos, "is died");
				pthread_mutex_lock(&info->print);
				return (NULL);
			}
		}
	}
}

int	create_philo(t_info *info)
{
	pthread_t	trd;
	int			i;

	i = -1;
	while (++i < info->nbr_of_philo)
	{
		info->time = get_time();
		info->philos[i].last_eat = get_time();
		if (pthread_create(&info->philos[i].thrtead, NULL,
				philo, &info->philos[i]))
			return (printf("Error create thread"), 0);
	}
	if (pthread_create(&trd, NULL, monitor, info))
		return (printf("Error create thread"), 0);
	if (pthread_join(trd, NULL))
		return (printf("Error create thread"), 0);
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	info->forks = malloc(sizeof(t_info) * info->nbr_of_philo);
	info->philos = malloc(sizeof(t_philo) * info->nbr_of_philo);
	if (!info->forks || !info->philos)
		return (printf("Error de malloc"), 0);
	i = -1;
	while (++i < info->nbr_of_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (printf("Error de mutex"), 0);
	}
	if (pthread_mutex_init(&info->print, NULL))
		return (printf("Error de mutex"), 0);
	add_info_philo(info);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (!(check_argumment(ac, av)))
		return (printf("Invalid argumment"), 0);
	if (!(add_info(&info, ac, av)))
		return (printf("Invalid argumment"), 0);
	if (!(init_philo(&info)))
		return (ft_free(&info), 0);
	if (create_philo(&info))
		return (ft_free(&info), 0);
	ft_free(&info);
	return (0);
}
