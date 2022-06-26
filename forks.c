/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:47:55 by lloko             #+#    #+#             */
/*   Updated: 2022/06/26 15:23:59 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[left]);
	pthread_mutex_lock(&philo->data->forks[right]);
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d taken forks\n", get_time() - philo->data->t_start, philo->id);
	// pthread_mutex_unlock(&philo->data->print);
	// pthread_mutex_lock(&philo->data->print);
	// printf("%lu %d taken forks\n", get_time() - philo->data->t_start, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	put_forks(t_philo*philo)
{
	pthread_mutex_unlock(&philo->data->forks[left]);
	pthread_mutex_unlock(&philo->data->forks[right]);
}

void	free_forks(pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
