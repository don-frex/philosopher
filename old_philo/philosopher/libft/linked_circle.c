/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:22:54 by asaber            #+#    #+#             */
/*   Updated: 2023/05/26 22:37:22 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	linked_circle(t_philo *philos)
{
	t_philo	*first_philo;

	first_philo = philos;
	while (philos->next)
	{
		philos = philos->next;
	}
	philos->next = first_philo;
}
