/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@proton.me>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:40:42 by hallfana          #+#    #+#             */
/*   Updated: 2024/12/23 23:34:07 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define __PORT__ 5001
#define __ADDRESS__ "127.0.0.1"
#define __BUFFER_SIZE__ 1024

typedef struct s_client
{
	int sockfd;
	struct sockaddr_in cli_addr;
	struct s_client *next;
} t_client;

typedef struct s_data
{
	t_client *clients;
	pthread_mutex_t mutex;
} t_data;

int t_client_count(t_data *data)
{
	pthread_mutex_lock(&data->mutex);
	int n = 0;
	t_client *tmp = data->clients;

	while (tmp != NULL)
	{
		n++;
		tmp = tmp->next;
	}
	pthread_mutex_unlock(&data->mutex);
	return (n);
}

void t_client_add(t_data *data, t_client *client)
{
	pthread_mutex_lock(&data->mutex);
	if (data->clients == NULL)
	{
		data->clients = client;
	}
	else
	{
		t_client *tmp = data->clients;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = client;
	}
	pthread_mutex_unlock(&data->mutex);
}

void t_client_remove(t_data *data, t_client *client)
{
	pthread_mutex_lock(&data->mutex);
	if (data->clients == client)
	{
		data->clients = client->next;
	}
	else
	{
		t_client *tmp = data->clients;
		while (tmp->next != client)
		{
			tmp = tmp->next;
		}
		tmp->next = client->next;
	}
	pthread_mutex_unlock(&data->mutex);
}

void cli_user(t_data *data, t_client *client)
{
	char buffer[__BUFFER_SIZE__];
	int n;

	while (1)
	{
		printf("[tinyC2 @ %s:%d] > ", inet_ntoa(client->cli_addr.sin_addr), ntohs(client->cli_addr.sin_port));
		bzero(buffer, __BUFFER_SIZE__);
		fgets(buffer, __BUFFER_SIZE__, stdin);
		if (!strncmp("exit", buffer, 4))
		{
			break;
		}
		else if (!strncmp("ping", buffer, 4))
		{
			n = send(client->sockfd, "ping\n", 5, 0);
			if (n < 0)
				printf("->Error sending data\n");
		}
	}
}

void *cli(void *param)
{
	t_data *data = (t_data *)param;
	t_client *client = NULL;
	char buffer[__BUFFER_SIZE__];
	int n;

	while (1)
	{
		printf("[tinyC2 @ NaN] > ");
		bzero(buffer, __BUFFER_SIZE__);
		fgets(buffer, __BUFFER_SIZE__, stdin);
		if (!strncmp("exit", buffer, 4))
		{
			break;
		}
		else if (!strncmp("list", buffer, 4))
		{
			n = t_client_count(data);
			if (n == 0)
			{
				printf("->No clients connected\n");
			}
			else
			{
				printf("->Total clients connected: %d\n", n);
				client = data->clients;
				while (client != NULL)
				{
					printf("\t->%s:%d\n", inet_ntoa(client->cli_addr.sin_addr), ntohs(client->cli_addr.sin_port));
					client = client->next;
				}
				client = NULL;
			}
			continue;
		}
		else if (!strncmp("select", buffer, 6))
		{

			char *ip = strtok(buffer, " ");
			ip = strtok(NULL, " ");
			char *port_str = strtok(NULL, " ");
			if (ip == NULL || port_str == NULL)
			{
				printf("->Invalid ip or port\n");
				continue;
			}
			int port = atoi(port_str);
			if (port == 0)
			{
				printf("->Invalid port\n");
				continue;
			}
			client = data->clients;
			while (client != NULL)
			{
				if (!strncmp(inet_ntoa(client->cli_addr.sin_addr), ip, strlen(ip)) && ntohs(client->cli_addr.sin_port) == port)
				{
					break;
				}
				client = client->next;
			}
			if (client == NULL)
			{
				printf("->Client not found\n");
				continue;
			}
			cli_user(data, client);
		}
	}

	exit(0);
}

int main(void)
{
	int sockfd, newsockfd;
	struct sockaddr_in srv_addr, cli_addr;
	socklen_t cli_len;
	t_data data;
	t_client *client = NULL;

	data.clients = NULL;
	pthread_mutex_init(&data.mutex, NULL);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("Error opening socket");
		exit(1);
	}
	// Set socket options
	int opt = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
	{
		perror("Error setting socket options");
		exit(1);
	}

	bzero((char *)&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = inet_addr(__ADDRESS__);
	srv_addr.sin_port = htons(__PORT__);

	if (bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0)
	{
		perror("Error on binding");
		exit(1);
	}

	listen(sockfd, 5);
	cli_len = sizeof(cli_addr);

	pthread_t thread_cli;
	pthread_create(&thread_cli, NULL, cli, (void *)&data);

	while (1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
		if (newsockfd < 0)
		{
			perror("Error on accept");
			continue;
		}
		client = (t_client *)malloc(sizeof(t_client));
		client->sockfd = newsockfd;
		client->cli_addr = cli_addr;
		client->next = NULL;
		t_client_add(&data, client);
	}

	pthread_mutex_destroy(&data.mutex);
	close(sockfd);
	return (0);
}
