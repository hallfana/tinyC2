/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:25 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/20 09:15:01 by hallfana         ###   ########.fr       */
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
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>

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
#  define _TC_SERVER_ADDRESS "127.0.0.1"
# endif

# ifndef _TC_SERVER_PORT
#  define _TC_SERVER_PORT 8080
# endif

# ifndef _TC_SERVER_BACKLOG
#  define _TC_SERVER_BACKLOG 16
# endif

/* ------------------------- STRUCT ------------------------- */

typedef struct in_addr		t_in_addr;
typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;

typedef struct s_server
{
	int				server_fd;
	int				thread_id;
	t_in_addr		*server_ip;
	t_sockaddr_in	*srv;
}				t_server;

/* ------------------------- FUNCTION ------------------------- */

//		utils.c
int		_tc_strlen(char *str);
int		_tc_nbrlen(int n);

//		print.c
void	_tc_error(t_server *server, char *msg);
void	_tc_warning(char *msg);
void	_tc_info(char *msg);

//		server.c
int 	_tc_init_server(t_server *server);

//		cleanup.c
void	_tc_clean_exit(t_server *server, int status);

//		format.c
char	*_tc_format(t_server *server, char *fmt, ...);

//		listener.c
void	_tc_init_listener(t_server *server);
#endif