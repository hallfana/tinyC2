/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:43:56 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 23:49:54 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	_tc_add_client(t_client **head, t_client *client)
{
	t_client	*tmp;

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
}

void	_tc_remove_client(t_client **head, t_client *client)
{
	t_client	*tmp;
	t_client	*prev;

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
}

t_client	*_tc_find_client(t_client *head, int client_id)
{
	t_client	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->client_id == client_id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
