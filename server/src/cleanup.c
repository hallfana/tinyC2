/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:22:26 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 03:26:03 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void	_tc_cleanup_server(t_server *server)
{
	if (server->srv)
		free(server->srv);
	if (server->server_ip)
		free(server->server_ip);
}

void	_tc_clean_exit(t_server *server, int status)
{
	if (server)
		_tc_cleanup_server(server);
	exit(status);
}