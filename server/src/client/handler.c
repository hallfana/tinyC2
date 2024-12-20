/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:31:48 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 10:08:43 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

void	_tc_handler(t_server *server, t_client *client)
{
	char	*str;

	while (client->client_thread == NULL)
	{
		str = _tc_format(server, "Client %d is waiting for a thread\n", client->client_fd);
		_tc_info(str);
		free(str);
	}
	str = _tc_format(server, "Client %d connected\n", client->client_fd);
	_tc_info(str);
	free(str);
	while (1)
	{
		pause();
	}
}