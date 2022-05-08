/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:45 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:52:49 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutex_init(t_table *table)
{
	int	idx;

	if (pthread_mutex_init(&(table->write), NULL))
		return (-1);
	if (pthread_mutex_init(&(table->eating), NULL))
		return (-1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (!(table->forks))
		return (-1);
	idx = 0;
	while (idx < table->philo_num)
	{
		if (pthread_mutex_init(&(table->forks[idx]), NULL))
			return (-1);
		idx++;
	}
	return (0);
}

int	ft_philo_init(t_table *table)
{
	int	idx;

	idx = 0;
	table->philo = malloc(sizeof(t_table) * table->philo_num);
	if (!(table->philo))
		return (-1);
	while (idx < table->philo_num)
	{
		table->philo[idx].id = idx;
		table->philo[idx].left_fork = idx;
		table->philo[idx].right_fork = (idx + 1) % table->philo_num;
		table->philo[idx].check_dead_time = 0;
		table->philo[idx].eat_cnt = 0;
		table->philo[idx].table = table;
		idx++;
	}
	return (0);
}

int	ft_philo_input(t_table *table, char *argv[], int argc)
{
	table->philo_num = ft_atoif(argv[1]);
	table->time_to_die = ft_atoif(argv[2]);
	table->time_to_eat = ft_atoif(argv[3]);
	table->time_to_sleep = ft_atoif(argv[4]);
	table->must_eat_num = 0;
	table->die = 0;
	table->eat_check = 0;
	table->start_time = 0;
	if (ft_check_init(table))
		return (-1);
	if (argc == 6)
	{
		table->must_eat_num = ft_atoif(argv[5]);
		if (table->must_eat_num <= 0)
			return (-1);
	}
	if (ft_mutex_init(table))
		return (-1);
	if (ft_philo_init(table))
		return (-1);
	return (0);
}
