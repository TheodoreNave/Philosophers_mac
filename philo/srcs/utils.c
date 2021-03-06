/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:19:46 by tnave             #+#    #+#             */
/*   Updated: 2022/02/15 15:55:19 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_all(t_philo *philo, t_utils *utils, int error)
{
	int	i;

	i = 0;
	while (i < utils->nb_philo)
	{
		if (philo)
			pthread_mutex_destroy(&philo[i].eating);
		if (utils->forks)
			pthread_mutex_destroy(&utils->forks[i]);
		i++;
	}
	if (philo)
	{
		pthread_mutex_destroy(&philo->utils->lock);
		pthread_mutex_destroy(&philo->utils->count_protect);
		pthread_mutex_destroy(&philo->utils->is_dead);
		free(philo);
	}
	if (utils->forks)
		free(utils->forks);
	if (error == 1)
		return (1);
	else
		return (0);
}

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

void	*ft_calloc(int size)
{
	void	*memory;

	memory = malloc(size);
	if (!memory)
		return (NULL);
	memset(memory, 0, size);
	return (memory);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
