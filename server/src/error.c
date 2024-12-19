/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:41:31 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/19 20:53:01 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	_tc_error(char *msg)
{
	if (DEBUG && DEBUG_LEVEL >= 1)
	{
		write(1, RED, _tc_strlen(RED));
		write(1, msg, _tc_strlen(msg));
		write(1, RST, _tc_strlen(RST));
	}
	exit(1);
}