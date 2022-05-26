/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:07 by ebouabba          #+#    #+#             */
/*   Updated: 2022/05/26 19:19:56 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int		i;
	int		signe;
	int		num;

	i = 0;
	signe = 1;
	num = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	return (num * signe);
}

int	check_argumment(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (ac > i)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	add_info_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_of_philo)
	{
		info->philos[i].info = info;
		if (info->nbr_of_must_eat > 0)
		{
			info->philos[i].num_eat = info->nbr_of_must_eat;
			info->philos[i].count_eat = 0;
		}
		info->philos[i].id = i;
		if (i + 1 >= info->nbr_of_philo)
			info->philos[i].id_next = 0;
		else
			info->philos[i].id_next = i + 1;
	}
}

int	add_info(t_info *info, int ac, char **av)
{
	info->nbr_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->nbr_of_must_eat = -1;
	if (ac == 6)
	{
		info->nbr_of_must_eat = ft_atoi(av[5]);
		if (info->nbr_of_must_eat < 1)
			return (printf("Invalid argumment"), 0);
	}
	if (info->nbr_of_philo < 1 || info->time_to_die < 1
		|| info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (0);
	return (1);
}
