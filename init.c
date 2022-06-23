/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:51:42 by lloko             #+#    #+#             */
/*   Updated: 2022/06/23 21:58:42 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*init_data(char **argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->eat_raz = -1;
	if (argc == 5)
	{
		data->eat_raz = ft_atoi(argv[5]);
		if (data->eat_raz <= 0)
			ft_error(1);
	}
	return (data);
}

t_philo	*init_philo(int i, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i + 1;
	philo->data = data;
	philo->t_eat = data->eat_raz;
	philo->right = i;
	philo->left = (i + data->eat_raz - 1) % data->num_philo;
	if (i == 0)
	{
		philo->left = i;
		philo->right = (i + data->eat_raz - 1) % data->num_philo;
	}
	pthread_mutex_init(&philo->mute, NULL);
	data->philo.forks = forks_init(data->num_philo);
	if (!data->philo.forks)
	{
		free(data);
		return (NULL);
	}
	pthread_mutex_init(&data->philo.print, NULL);
	return (philo);
}
