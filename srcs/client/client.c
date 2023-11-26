/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:39 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 11:45:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minitalk.h"

static t_global	g_global = {0, 0, -1, 0, NULL, NULL, NULL, NULL, 0, 0, 1};

void	signal_handler(int signo)
{
	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		g_global.rec_char <<= 1;
		if (signo == SIGUSR1)
			g_global.rec_char |= 1;
		g_global.bits_received++;
		if (g_global.bits_received == 8)
		{
			ft_printf("%c", g_global.rec_char);
			g_global.rec_char = 0;
			g_global.bits_received = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	char				*message;
	char				*msg_len;

	if (argc != 3)
		return (ft_printf("./client [pid] [message]\n"), 1);
	server_pid = ft_atoi(argv[1]);
	msg_len = ft_itoa(ft_strlen(argv[2]));
	message = argv[2];
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ft_send_message(msg_len, server_pid))
		ft_send_message(message, server_pid);
	free(msg_len);
	exit(0);
}
