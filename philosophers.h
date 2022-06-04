/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:03:12 by lloko             #+#    #+#             */
/*   Updated: 2022/06/04 19:59:15 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <tread.h>

typedef struct s_init
{
	unsigned long	t_eat;
	unsigned long	t_die;
	unsigned long	t_sleep;
	unsigned long	t_start;
	int				num_philo;
	int				eat_raz;
}				t_init;

typedef struct s_data
{
	t_init	init;
}				t_data;

int	ft_error(int i);
int	check_arg(int argc, char **argv, t_data *data);

#endif
