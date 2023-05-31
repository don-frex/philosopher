/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:48:12 by asaber            #+#    #+#             */
/*   Updated: 2023/05/31 17:17:41 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct infos
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*died;
	u_int64_t		start;
}		t_infos;

typedef struct philo
{
	int				id;
	int				n_meals;
	pthread_t		ph_thread;
	pthread_mutex_t	*philo_fork;
	t_infos			*info;
	u_int64_t		last_dining;
	struct philo	*next;
}					t_philo;

t_infos		*init_data(int argc, char **argv, t_philo *philos);
void		init_mutex(t_philo *philos, int n_philos);
void		create_thread(t_infos *data, t_philo *philos);
u_int64_t	get_time(void);
int			ft_isdigit(int c);
int			ft_atoi(const char *c);
t_philo		*ft_lstnew(int id);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		linked_circle(t_philo *philos);

#endif