/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:32:29 by asaber            #+#    #+#             */
/*   Updated: 2023/06/15 13:29:09 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		printf("TIME FAILURE\n");
	return ((tv.tv_sec * (u_int16_t)1000) + (tv.tv_usec / 1000));
}

void	get_id(t_philo *philos, int n_philo)
{
	int	i;

	i = 1;
	while (i <= n_philo)
	{
		philos->id = i;
		philos = philos->next;
	}
}

t_infos	*init_data(int argc, char **argv, t_philo *philos)
{
	t_infos	*data;
	int		count;

	data = malloc(sizeof(t_infos));
	data->print = malloc(sizeof(pthread_mutex_t));
	data->death = malloc(sizeof(pthread_mutex_t));
	data->eat = malloc(sizeof(pthread_mutex_t));
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->n_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->check_print = 1;
	pthread_mutex_init(data->death, NULL);
	pthread_mutex_init(data->print, NULL);
	pthread_mutex_init(data->eat, NULL);
	count = 0;
	while (count++ < data->n_of_philos)
	{
		philos->info = data;
		philos = philos->next;
	}
	return (data);
}

void	init_mutex(t_philo *philos, int n_philos)
{
	while (n_philos--)
	{
		philos->philo_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos->philo_fork, NULL);
		philos = philos->next;
	}
}
