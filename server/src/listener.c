/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:42:32 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 04:54:37 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void _tc_listen_server(t_server *server)
{
	int		ret;
	char	*str;

	ret = listen(server->server_fd, _TC_SERVER_BACKLOG);
	if (ret == -1)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error(server, "Error listening to server\n");
	}
	str = _tc_format(server, "Server listening on %s:%d\n", inet_ntoa(server->srv->sin_addr), ntohs(server->srv->sin_port));
	_tc_info(str);
	free(str);
}

static void *_tc_accept_loop(void *arg)
{
	t_server		*server;
	t_sockaddr_in	client;
	socklen_t		client_len;
	int				client_fd;
	char			*str;

	server = (t_server *)arg;
	client_len = sizeof(client);
	while (1)
	{
		client_fd = accept(server->server_fd, (t_sockaddr *)&client, &client_len);
		if (client_fd == -1)
		{
			if (DEBUG && DEBUG_LEVEL >= 1)
				_tc_warning("Error accepting client\n");
		}
		else
		{
			str = _tc_format(server, "Client connected from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			_tc_info(str);
			free(str);
		}
	}
	return (NULL);
}

static void _tc_init_main_thread(t_server *server)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, _tc_accept_loop, server) != 0)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error(server, "Error creating main thread\n");
	}
}

void _tc_init_listener(t_server *server)
{
	_tc_listen_server(server);
	_tc_init_main_thread(server);
}