/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:33:53 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 04:17:37 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int		_tc_format_len(char *fmt, va_list args)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == 's')
				len += _tc_strlen(va_arg(args, char *));
			else if (fmt[i + 1] == 'd')
				len += _tc_nbrlen(va_arg(args, int));
			i++;
		}
		else
			len++;
		i++;
	}
	return (len);
}

char	*_tc_format(t_server *server, char *fmt, ...)
{
	va_list	args;
	char	*str;
	int		len;
	int		i;

	va_start(args, fmt);
	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] == 's')
			{
				len += _tc_strlen(va_arg(args, char *));
				i++;
			}
			else if (fmt[i + 1] == 'd')
			{
				len += _tc_nbrlen(va_arg(args, int));
				i++;
			}
		}
		else
			len++;
		i++;
	}
}