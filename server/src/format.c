/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 03:33:53 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 04:25:48 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static int		_tc_format_len(char *fmt, va_list args)
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
	len = _tc_format_len(fmt, args);
	va_end(args);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		if (DEBUG && DEBUG_LEVEL >= 1)
			_tc_error(server, "Error allocating memory for formatted string\n");
	}
	va_start(args, fmt);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 's')
			{
				char *s = va_arg(args, char *);
				while (*s)
					str[i++] = *s++;
			}
			else if (*(fmt + 1) == 'd')
			{
				int n = va_arg(args, int);
				int j = _tc_nbrlen(n);
				while (j--)
				{
					str[i + j] = n % 10 + '0';
					n /= 10;
				}
				i += _tc_nbrlen(n);
			}
			fmt++;
		}
		else
			str[i++] = *fmt;
		fmt++;
	}
	str[i] = '\0';
	va_end(args);
	return (str);
}
