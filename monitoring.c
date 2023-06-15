/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:11:48 by asaber            #+#    #+#             */
/*   Updated: 2023/06/15 21:14:35 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	*ro_monitor(t_philo *philos)
{
	int		check;
	int		i;

	while (1)
	{
		i = 0;
		check = 1;
		while (i++ < philos->info->n_of_philos)
		{
			//pthread_mutex_lock(philos->info->eat);
			if (philos->n_meals < philos->info->must_eat)
			{
				//pthread_mutex_unlock(philos->info->eat);
				check = 0;
				break ;
			}
			//pthread_mutex_unlock(philos->info->eat);
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
	return (NULL);
}

void*	___dead(t_philo *philo )
{
	//pthread_mutex_lock(philo->info->death);
	if (philo->last_dining + philo->info->time_to_die
		<= get_time() - philo->info->start)
	{
		print(philo, "died");
		//pthread_mutex_lock(philo->info->print);
		philo->info->check_print = 0;
		//pthread_mutex_unlock(philo->info->print);
		return (1);
	}
	//pthread_mutex_unlock(philo->info->death);
	return (0);
}