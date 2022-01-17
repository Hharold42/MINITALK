/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:49:21 by hharold           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:01 by hharold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_chr(int pid, unsigned char byte)
{
	uint8_t	counter;

	counter = 1 << 7;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("bad pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("bad pid\n");
		}
		counter >>= 1;
		usleep(600);
	}
}

void	c_handler(char *str_pid, char *message)
{
	int	pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_chr(pid, *message);
		++message;
	}
	send_chr(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Data has been recevied.\n", 25);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		usage();
	signal(SIGUSR1, success);
	c_handler(argv[1], argv[2]);
	return (0);
}
