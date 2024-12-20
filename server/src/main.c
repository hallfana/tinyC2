/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:28 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 06:06:43 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int main(void)
{
	t_server server;
	_tc_init_server(&server);
	_tc_init_listener(&server);
	while (1)
	{
		pause();
	}
	_tc_clean_exit(&server, 0);
	return (0);
}