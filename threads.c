/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:34:29 by asaber            #+#    #+#             */
/*   Updated: 2023/06/15 23:01:25 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	umod_sleep(u_int64_t time_start, int to_sleep)
{
	while (get_time() - time_start < (u_int64_t) to_sleep)
		usleep(to_sleep);
}

void	print(t_philo *philo, char *text)
{
	pthread_mutex_lock(philo->info->print);
	if (philo->info->check_print)
	 	printf("%lld %d %s\n", get_time() - philo->info->start, philo->id, text);
	pthread_mutex_unlock(philo->info->print);
	if (text[3] == 's')
		umod_sleep(get_time(), philo->info->time_to_sleep);
	if (text[3] == 'e')
		umod_sleep(get_time(), philo->info->time_to_eat);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info->death);
	philo->last_dining = get_time() - philo->info->start;
	pthread_mutex_unlock(philo->info->death);
	print(philo, "is eating");
	pthread_mutex_lock(philo->info->eat);
	philo->n_meals++;
	pthread_mutex_unlock(philo->info->eat);
	pthread_mutex_unlock(philo->philo_fork);
	pthread_mutex_unlock(philo->next->philo_fork);
}

int	___dead(t_philo *philo )
{
	pthread_mutex_lock(philo->info->death);
	if (philo->last_dining + philo->info->time_to_die
		<= get_time() - philo->info->start)
	{
		print(philo, "died");
		pthread_mutex_lock(philo->info->print);
		philo->info->check_print = 0;
		pthread_mutex_unlock(philo->info->print);
		return (1);
	}
	pthread_mutex_unlock(philo->info->death);
	return (0);
}

void	*ro_monitor(void *arg)
{
	t_philo	*philos;
	int		check;
	int		i;


	philos = (t_philo *) arg;
	while (1)
	{
		i = 0;
		check = 1;
		if (___dead(philos))
			return NULL;
		if (philos->info->must_eat > 0)
		{
			while (i++ < philos->info->n_of_philos)
			{
					pthread_mutex_lock(philos->info->eat);
					if (philos->n_meals < philos->info->must_eat)
					{
						pthread_mutex_unlock(philos->info->eat);
						check = 0;
						break ;
					}
					pthread_mutex_unlock(philos->info->eat);
				philos = philos->next;
			}
			if (check)
			{
				pthread_mutex_lock(philos->info->print);
				philos->info->check_print = 0;
				pthread_mutex_unlock(philos->info->print);
				printf("All Philosophers have eating enough\n");
				return NULL;
			}
		}
	}
	return (NULL);
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
		is_eating(philo);
		print(philo, "is sleeping");
		print(philo, "is thinking");
	}
	return (NULL);
}

void	 create_thread(t_infos *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor;

	i = 1;
	data->start = get_time();
	while (i <= data->n_of_philos)
	{
		pthread_create(&philos->ph_thread, NULL, &routen, philos);
		usleep(100);
		philos = philos->next;
		i++;
	}
	pthread_create(&monitor, NULL, &ro_monitor, philos);
	pthread_join(monitor, NULL);
}
