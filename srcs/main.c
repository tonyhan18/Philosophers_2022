/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:51:40 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:51:45 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (ft_error("[Error] number of argc is not fitted"));
	if (ft_philo_input(&table, argv, argc))
		return (ft_error("[Error] error in parameter"));
	if (ft_philo_start(&table, (&table)->philo))
		return (ft_error("[Error] check philo start"));
	return (0);
}
