/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:31:48 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/22 01:57:55 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	*_tc_handler(void *param)
{
	char	*str;
	t_thread_param	*thread_param;
	t_server		*server;
	t_client		*client;

	thread_param = (t_thread_param *)param;
	server = thread_param->server;
	client = thread_param->client;
	while (client->client_thread == NULL)
		usleep(1000);
	
	_tc_add_client(&server->client_list, client, server->client_list_mutex);
	while (1)
	{
		char *buffer;
		int bytes_read;

		buffer = (char *)malloc(sizeof(char) * _TC_SERVER_BUFFER_SIZE);
		bytes_read = recv(client->client_fd, buffer, sizeof(buffer) - 1, 0);
		if (bytes_read <= 0)
		{
			_tc_remove_client(&server->client_list, client, server->client_list_mutex);
			break;
		}
		buffer[bytes_read] = '\0';
		_tc_info(buffer);
		free(buffer);
	}
	return (NULL);
}
