/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:43:56 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 23:59:11 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	_tc_add_client(t_client **head, t_client *client, pthread_mutex_t *mutex)
{
	t_client	*tmp;

	pthread_mutex_lock(mutex);
	if (*head == NULL)
	{
		*head = client;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = client;
	}
	pthread_mutex_unlock(mutex);
}

void	_tc_remove_client(t_client **head, t_client *client, pthread_mutex_t *mutex)
{
	t_client	*tmp;
	t_client	*prev;

	pthread_mutex_lock(mutex);
	tmp = *head;
	prev = NULL;
	while (tmp != NULL)
	{
		if (tmp == client)
		{
			if (prev == NULL)
				*head = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	pthread_mutex_unlock(mutex);
}

t_client	*_tc_find_client(t_client *head, int client_id, pthread_mutex_t *mutex)
{
	t_client	*tmp;

	pthread_mutex_lock(mutex);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->client_id == client_id)
		{
			pthread_mutex_unlock(mutex);
			return (tmp);
		}
		tmp = tmp->next;
	}
	pthread_mutex_unlock(mutex);
	return (NULL);
}
