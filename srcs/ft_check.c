/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:57 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:52:59 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_init(t_table *table)
{
	if (table->philo_num < 1 || table->philo_num > 200
		|| table-> time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (-1);
	if  (table->philo_num == -1 || table->time_to_die == -1 || table->time_to_eat == -1 || table->time_to_sleep == -1)
		return (-1);
	return (0);
}

void	ft_eat_check(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (table->must_eat_num != 0 && i < table->philo_num
		&& philo[i].eat_cnt > table->must_eat_num)
		i++;
	if (i == table->philo_num)
		table->eat_check = 1;
}

void	ft_death_check(t_table *table, t_philo *philo)
{
	int		i;

	while (!(table->eat_check))
	{
		i = 0;
		while ((i < table->philo_num) && (!(table->die)))
		{
			pthread_mutex_lock(&(table->eating));
			if ((ft_time() - philo[i].check_dead_time) > table->time_to_die)
			{
				ft_printf(table, "died", i);
				table->die = 1;
			}
			pthread_mutex_unlock(&(table->eating));
			i++;
		}
		if (table->die)
			break ;
		ft_eat_check(table, table->philo);
	}
}
