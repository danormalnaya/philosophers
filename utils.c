/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:26:11 by lloko             #+#    #+#             */
/*   Updated: 2022/06/04 19:35:17 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int i)
{
	if (i == 1)
		printf("Wrong arguments: you should use positive integers\n");
	if (i == 2)
		printf("Wrong numbers of arguments: use number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"\n);
	return (0);
}
