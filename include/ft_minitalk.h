/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:48:20 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 11:45:35 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "../libft/srcs/libft.h"
# include <signal.h>
# include <stdio.h>

typedef struct s_global
{
	char	rec_char;
	int		bits_received;
	pid_t	client_pid;
	int		is_received;
	char	*str_server;
	char	*str_len_s;
	char	*str_client;
	char	*str_len_c;
	int		int_len;
	int		cur_len;
	int		get_len;
}		t_global;

int		ft_send_message(char *message, int server_pid);
char	*ft_charjoin(char const *s1, char const c2);

#endif