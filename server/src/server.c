/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:40:19 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/19 22:13:03 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	_tc_allocate_server(t_server *server)
{
	server->srv = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	if (server->srv == NULL)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error allocating memory for server\n");
	}
	server->server_ip = (struct in_addr*)malloc(sizeof(struct in_addr));
	if (server->server_ip == NULL)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error allocating memory for server IP\n");
	}
}

void	_tc_populate_server_ip(t_server *server)
{
	int			ret;

	ret = inet_pton(AF_INET, _TC_SERVER_ADDRESS, server->server_ip);
	if (ret == -1)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error converting IP address\n");
	}
	server->srv->sin_family = AF_INET;
	server->srv->sin_port = htons(_TC_SERVER_PORT);
	server->srv->sin_addr.s_addr = server->server_ip->s_addr;
}

int _tc_init_server(t_server *server)
{
	int	ret;

	_tc_allocate_server(server);
	_tc_populate_server_ip(server);
	server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->server_fd == -1)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error creating socket\n");
		return (-1);
	}
	ret = bind(server->server_fd, (struct sockaddr *)server->srv, sizeof(*server->srv));
	if (ret == -1)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error binding socket\n");
		return (-1);
	}	
	return (0);
}
