/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:40:19 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/19 20:52:56 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int _tc_init_server(t_server *server)
{
	server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->server_fd == -1)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error("Error creating socket\n");
		return (-1);
	}
	return (0);
}