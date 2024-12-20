/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:28 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 23:54:12 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void *_tc_debug_print(void *param)
{
	t_server	*server;
	char		*str;

	server = (t_server *)param;
	while (1)
	{
		// print each client stored in the linked list
		t_client *tmp = server->client_list;
		while (tmp != NULL)
		{
			str = _tc_format(server, "Client %d %s:%d\n", tmp->client_fd, inet_ntoa(tmp->client->sin_addr), ntohs(tmp->client->sin_port));
			_tc_info(str);
			free(str);
			tmp = tmp->next;
		}
		sleep(5);
	}
	return (NULL);
}

int main(void)
{
	t_server server;
	_tc_init_server(&server);
	_tc_init_listener(&server);
	pthread_t debug_thread;
	pthread_create(&debug_thread, NULL, _tc_debug_print, &server);
	while (1)
	{
		pause();
	}
	_tc_clean_exit(&server, 0);
	return (0);
}