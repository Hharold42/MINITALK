/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharold <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:42:29 by hharold           #+#    #+#             */
/*   Updated: 2022/01/17 14:58:39 by hharold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <zconf.h>
# include "libft/libft.h"

# define BUFFSIZE 1024

typedef struct s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	bool		all_receive;
	bool		buff_overflow;
}				t_stack;

t_stack			g_to_print = {{0}, 1 << 7, 0, 0, 0};

void	error(char *str_error);

#endif
