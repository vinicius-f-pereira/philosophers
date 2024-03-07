/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:43:36 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/06 21:30:59 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/**
 * needed for project
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>

/**
 * for definitions and types
 */
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>

# define YLW "\033[1;33m"
# define GRN "\033[1;32m"
# define RED "\033[1;31m"
# define ORG "\033[93m"
# define BLU "\033[94m"
# define CYA "\033[36m"
# define RST "\033[0m"
# define MAG "\033[95m"
# define LRED "\033[91m"

/* semaphores definitions */
# define S_FORKS "/forks"
# define S_TABLE "/table"
# define S_PRINT "/print"
# define S_DEATH "/lock_death"

/* ANOTHER ENUMS */
enum	e_philo
{
	DEBUG_MODE,
	MAX_PHILO = 200,
};

/* PHILO STATUS */
typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_st;

/* MUTEX HANDLE */
typedef enum e_mtx
{
	CREATE,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	DETACH,
	JOIN,
	OPEN,
	CLOSE,
	POST,
	WAIT,
	UNLINK,
	ONE = 1,
}	t_code;

/* HANDLE TIME */
typedef enum e_time_code
{
	SECOND,
	MILLISEC,
	MICROSEC,
}	t_time_code;

typedef pthread_mutex_t	t_mtx;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	int			ph_nb;
	int			max_meals;
	long		eat;
	long		sleep;
	long		die;
	long		start;
	bool		end;
	bool		all_up;
	long		th_nbr;
	sem_t		*table_mtx;
	sem_t		*write_mtx;
	sem_t		*fork;
	t_philo		*philo;
	pthread_t	monitor;
}	t_table;

struct s_philo
{
	int			id;
	bool		full;
	long		meals;
	long		last_meal;
	sem_t		*philo_mtx;
	sem_t		*firts_fork;
	sem_t		*second_fork;
	t_table		*table;
	pthread_t	th_id;
};

/* entrance function */
void	check(int ac, char **av);
void	parser_input(t_table *table, char **av);
void	init(t_table *table);
void	run(int ac, char **av);
void	clean(t_table *table);

/* utils */
long	ft_atol(const char *nptr);
long	gettime(t_time_code time_code);
void	precise_usleep(long usec, t_table *table);
void	sem_exit(char *msg, t_table *table);

/* wrapper functions */
void	*safe_malloc(size_t bytes);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_code opcode);
void	safe_mtx_handle(sem_t *mutex, t_code opcode, char *name);

/* function to error */
void	error_exit(const char *message);

/* get, set and verify functions */
void	set_bool(sem_t *mtx, bool *dst, bool value);
bool	get_bool(sem_t *mtx, bool *value);
void	set_long(sem_t *mtx, long *dst, long value);
long	get_long(sem_t *mtx, long *value);
bool	simulation_status(t_table *table);

/* dinner */
void	wait_all_threads(t_table *table);
void	dinner_start(t_table *table);
void	*dinner_simulation(void *data);
void	write_status(t_st status, t_philo *philo, bool debug);
void	thinking(t_philo *philo, bool pre_simulation);
void	*lonely_day(void *arg);

/* syncro */
void	increase_long(sem_t *mutex, long *value);
void	unsync_philos(t_philo *philo);
bool	threads_running(sem_t *mtx, long *threads, long ph_nb);
void	*monitor(void *data);

/* str */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strmerge(char *s1, char *s2);

#endif //!PHILO_H
