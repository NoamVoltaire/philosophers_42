static void	pick_chopsticks(t_philosopher *philo)
{
	if (philo->nb_of_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->left_chopstick);
		monitoring(philo, TOOK);
		pthread_mutex_lock(philo->right_chopstick);
		monitoring(philo, TOOK);
	}
	else
	{
		pthread_mutex_lock(philo->right_chopstick);
		monitoring(philo, TOOK);
		pthread_mutex_lock(philo->left_chopstick);
		monitoring(philo, TOOK);
	}
}

static void	drop_chopsticks(t_philosopher *philo)
{
	if (philo->nb_of_philo % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_chopstick);
		monitoring(philo, DROPPED);
		pthread_mutex_unlock(philo->right_chopstick);
		monitoring(philo, DROP);
	}
	else
	{
		pthread_mutex_unlock(philo->right_chopstick);
		monitoring(philo, DROPPED);
		pthread_mutex_unlock(philo->left_chopstick);
		monitoring(philo, DROP);
	}
}