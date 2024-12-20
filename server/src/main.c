/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:28 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 04:50:38 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int main(void)
{
	t_server server;
	_tc_init_server(&server);
	_tc_init_listener(&server);
	_tc_clean_exit(&server, 0);
	return (0);
}