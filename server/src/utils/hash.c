/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:23:00 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/22 01:13:23 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

long	_tc_sdbm_hash(char *str)
{
	long	hash;
	int		c;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	if (hash < 0)
		hash = -hash;
	return (hash);
}