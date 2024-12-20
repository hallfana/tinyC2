/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:41:31 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 04:19:30 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	_tc_error(t_server *server, char *msg)
{
	if (DEBUG && DEBUG_LEVEL >= 1)
	{
		write(1, RED, _tc_strlen(RED));
		write(1, msg, _tc_strlen(msg));
		write(1, RST, _tc_strlen(RST));
	}
	_tc_clean_exit(server, 1);
}

void	_tc_warning(char *msg)
{
	if (DEBUG && DEBUG_LEVEL >= 2)
	{
		write(1, YELLOW, _tc_strlen(YELLOW));
		write(1, msg, _tc_strlen(msg));
		write(1, RST, _tc_strlen(RST));
	}
}

void	_tc_info(char *msg)
{
	if (DEBUG && DEBUG_LEVEL >= 3)
	{
		write(1, LIGTH_BLUE, _tc_strlen(LIGTH_BLUE));
		write(1, msg, _tc_strlen(msg));
		write(1, RST, _tc_strlen(RST));
	}
}