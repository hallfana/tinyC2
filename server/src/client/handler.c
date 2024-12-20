/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:31:48 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/21 19:30:41 by hallfana         ###   ########.fr       */
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
	{
		str = _tc_format(server, "Client %ld is waiting for a thread\n", client->client_id);
		_tc_info(str);
		free(str);
	}
	str = _tc_format(server, "Client %ld connected\n", client->client_id);
	_tc_info(str);
	free(str);
	_tc_add_client(&server->client_list, client, server->client_list_mutex);
	while (1)
	{
		pause();
	}
	return (NULL);
}
