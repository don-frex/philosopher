/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:56:03 by asaber            #+#    #+#             */
/*   Updated: 2023/05/26 20:49:30 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*ft_lstnew(int id)
{
	t_philo	*begin;

	begin = NULL;
	begin = (t_philo *) malloc(sizeof(t_philo));
	if (begin == 0)
		return (NULL);
	begin->id = id;
	begin->next = NULL;
	return (begin);
}
