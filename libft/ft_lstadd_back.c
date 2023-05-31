/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:25:56 by asaber            #+#    #+#             */
/*   Updated: 2023/05/26 20:26:49 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*end;

	end = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
		while (end->next)
			end = end->next;
		end->next = new;
		new->next = NULL;
}
