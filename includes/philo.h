/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:53:07 by chahan            #+#    #+#             */
/*   Updated: 2022/05/07 16:53:10 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	long long		check_dead_time;
	struct s_table	*table;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_table
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				die;
	int				eat_check;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	write;
	t_philo			*philo;
}				t_table;

int			ft_isspace(char c);
int			ft_atoi(char *str);
int			ft_error(char *s);
void		ft_printf(t_table *game, char *str, int id);

long long	ft_time(void);
void		ft_sleeping_time(t_table *game);
void		ft_eating_time(t_table *game);

void		ft_eat_check(t_table *game, t_philo *philo);
void		ft_death_check(t_table *game, t_philo *philo);
int			ft_check_init(t_table *game);

int			ft_mutex_init(t_table *game);
int			ft_philo_input(t_table *game, char *argv[], int argc);
int			ft_philo_init(t_table *game);

void		ft_philo_eat(t_table *game, t_philo *philo);
int			ft_philo_do(t_table *game, t_philo *philo);
void		*ft_pthread(void *philo);
void		ft_end_philo(t_table *game, t_philo *philo);
int			ft_philo_start(t_table *game, t_philo *philo);
void		ft_after_eating(t_table *game, t_philo *philo);

int			main(int argc, char *argv[]);

#endif
