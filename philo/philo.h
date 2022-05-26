/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:15:31 by ebouabba          #+#    #+#             */
/*   Updated: 2022/05/26 19:22:33 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				id_next;
	long			last_eat;
	int				count_eat;
	int				num_eat;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thrtead;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	long			time;
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_of_must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_info;

int		main(int ac, char **av);
int		check_argumment(int ac, char **av);
int		ft_atoi(char *s);
int		check_eating(t_philo *philo);
long	get_time(void);
void	ft_free(t_info *info);
void	print_message(t_philo *philo, char *str);
void	ft_usleep(long ms);
void	add_info_philo(t_info *info);
int		add_info(t_info *info, int ac, char **av);
#endif