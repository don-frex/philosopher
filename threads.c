/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:34:29 by asaber            #+#    #+#             */
/*   Updated: 2023/05/31 21:41:30 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *text)
{
	// int check;
	// if (text[0] == 'd')
	// 	check = 0;
	// else
	// 	check = 1;
	// pthread_mutex_lock(philo->info->died);
	// if 
	printf("%lld %d %s\n", get_time() - philo->info->start, philo->id, text);
	if (text[3] == 's')
		usleep(philo->info->time_to_sleep * 1000);
	// pthread_mutex_unlock(philo->info->died);

}

void	is_eating(t_philo *philo)
{
	philo->last_dining = get_time() - philo->info->start;
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->philo_fork);
	pthread_mutex_unlock(philo->next->philo_fork);
}

void	___dead(t_philo *philo )
{
	if (philo->last_dining + philo->info->time_to_die < get_time() - philo->info->start)
	{
		print(philo, "died");
		exit(1);
	}
}

void	*routen(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(philo->philo_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->next->philo_fork);
		print(philo, "has taken a fork");
		print(philo, "is eating");
		is_eating(philo);
		print(philo, "is sleeping");
		print(philo, "is thinking");
	}
	return (NULL);
}


void	create_thread(t_infos *data, t_philo *philos)
{
	int		i;

	i = 1;
	while (i <= data->n_of_philos)
	{
		pthread_create(&philos->ph_thread, NULL, &routen, philos);
		usleep(100);
		philos = philos->next;
		i++;
	}
	while (1)
	{
		___dead(philos);
		philos = philos->next;
	}
}
