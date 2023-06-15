/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:42:56 by asaber            #+#    #+#             */
/*   Updated: 2023/06/01 16:46:49 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*work(void *viland)
{
	printf("lalal\n");
	return (viland);
}

t_philo	*creat_philos(int n_philo)
{
	int		i;
	t_philo	*philos;
	t_philo	*first_philo;

	i = 1;
	philos = ft_lstnew(i);
	first_philo = philos;
	while (i++ < n_philo)
		ft_lstadd_back(&philos, ft_lstnew(i));
	linked_circle(philos);
	return (philos);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_infos		*data;

	if (argc >= 5 && argc <= 6)
	{
		philos = creat_philos(ft_atoi(argv[1]));
		data = init_data(argc, argv, philos);
		init_mutex(philos, data->n_of_philos);
		create_thread(data, philos);
	}
	return (0);
}
