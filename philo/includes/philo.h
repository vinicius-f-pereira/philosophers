/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:43:36 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/24 01:44:55 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/**
 * needed for project
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

/**
 * for definitions and types
 */
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <inttypes.h>

typedef struct	s_time
{
	double	eat;
	double	sleep;
	double	die;
}	t_time;

typedef struct	s_fork
{
	int	fork;
}	t_fork;

typedef struct	s_table
{
	int	idkyet;
}	t_table;
	
typedef struct	s_philo
{
	t_time	*time;
	t_fork	*fork;
	t_table	*table;
}	t_philo;

#endif // !PHILO_H