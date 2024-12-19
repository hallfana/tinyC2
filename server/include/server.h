/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:25 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/19 20:48:19 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/* ------------------------- INCLUDE ------------------------- */

# include <unistd.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

/* ------------------------- DEFINE ------------------------- */

# ifndef DEBUG
#  define DEBUG 1
# endif

# ifndef DEBUG_LEVEL
#  define DEBUG_LEVEL 3
# endif

/*
** DEBUG_LEVEL 0: No debug message
** DEBUG_LEVEL 1: Print only error message
** DEBUG_LEVEL 2: Print only error and warning message
** DEBUG_LEVEL 3: Print only error, warning and info message
*/

# define RST "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define LIGTH_BLUE "\033[94m"

# ifndef _TC_SERVER_ADDRESS
#  define SERVER_ADDRESS "127.0.0.1"
# endif

# ifndef _TC_SERVER_PORT
#  define _TC_SERVER_PORT 8080
# endif

/* ------------------------- STRUCT ------------------------- */

typedef struct s_server
{
	int	server_fd;
}				t_server;

/* ------------------------- FUNCTION ------------------------- */

//	utils.c
int	_tc_strlen(char *str);

//		error.c
void	_tc_error(char *msg);

//	server.c
int _tc_init_server(t_server *server);
#endif