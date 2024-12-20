/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:22:26 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 23:04:36 by hallfana         ###   ########.fr       */
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