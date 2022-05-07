/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:09 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:52:11 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_error(char *s)
{
	printf("%s\n", s);
	return (-1);
}

void	ft_printf(t_table *table, char *str, int id)
{
	pthread_mutex_lock(&(table->write));
	if (!(table->die))
	{
		printf("%lld ms ", ft_time() - table->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(table->write));
	return ;
}
