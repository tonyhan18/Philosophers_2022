/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:24 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:52:27 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_sleeping_time(t_table *table)
{
	long long	sleep_time;
	long long	start_s_time;
	long long	now_s_time;

	sleep_time = (long long)(table->time_to_sleep);
	start_s_time = ft_time();
	while (!(table->die))
	{
		now_s_time = ft_time();
		if ((now_s_time - start_s_time) >= sleep_time)
			break ;
		usleep(10);
	}
}

void	ft_eating_time(t_table *table)
{
	long long	eat_time;
	long long	start_e_time;
	long long	now_e_time;

	eat_time = (long long)(table->time_to_eat);
	start_e_time = ft_time();
	while (!(table->die))
	{
		now_e_time = ft_time();
		if ((now_e_time - start_e_time) >= eat_time)
			break ;
		usleep(10);
	}
}
