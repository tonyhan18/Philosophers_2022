/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:34 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:52:37 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_eat(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&(table->eating));
	ft_printf(table, "is eating", philo->id);
	philo->check_dead_time = ft_time();
	pthread_mutex_unlock(&(table->eating));
	(philo->eat_cnt)++;
	ft_eating_time(table);
}

int	ft_philo_do(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&(table->forks[philo->left_fork]));
	ft_printf(table, "has taken a fork", philo->id);
	pthread_mutex_lock(&(table->forks[philo->right_fork]));
	ft_printf(table, "has taken a fork", philo->id);
	ft_philo_eat(philo->table, philo);
	pthread_mutex_unlock(&(table->forks[philo->right_fork]));
	pthread_mutex_unlock(&(table->forks[philo->left_fork]));
	if (table->eat_check)
		return (-1);
	return (0);
}

void	*ft_pthread(void *philo)
{
	t_table	*table;
	t_philo	*philo_copy;

	philo_copy = (t_philo *)philo;
	table = philo_copy->table;
	if (philo_copy->id % 2)
		usleep(table->time_to_eat * table->time_to_sleep);
	while (!(table->die))
	{
		if (ft_philo_do(table, philo_copy))
			break ;
		ft_printf(table, "is sleeping", philo_copy->id);
		ft_sleeping_time(table);
		ft_printf(table, "is thinking", philo_copy->id);
	}
	return (0);
}

void	ft_end_philo(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
		pthread_join(philo[i++].thread_id, NULL);
	i = 0;
	while (i < table->philo_num)
		pthread_mutex_destroy(&(table->forks[i++]));
	pthread_mutex_destroy(&(table->eating));
	pthread_mutex_destroy(&(table->write));
	free(table->philo);
	free(table->forks);
}

int	ft_philo_start(t_table *table, t_philo *philo)
{
	int		i;
	void	*v_philo;

	i = 0;
	table->start_time = ft_time();
	while (i < table->philo_num)
	{	
		philo[i].check_dead_time = ft_time();
		v_philo = (void *)&(philo[i]);
		if (pthread_create(&(philo[i].thread_id), NULL, ft_pthread, v_philo))
			return (-1);
		i++;
	}
	ft_death_check(table, table->philo);
	ft_end_philo(table, table->philo);
	return (0);
}
