/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:36:39 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 11:45:19 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minitalk.h"

static t_global	g_global = {0, 0, -1, 0, NULL, NULL, NULL, NULL, 0, 0, 1};

void	string_reset(void)
{
	free(g_global.str_client);
	free(g_global.str_len_c);
	g_global.str_client = NULL;
	g_global.str_len_c = NULL;
	g_global.cur_len = 0;
	g_global.int_len = 0;
	g_global.get_len = 1;
	g_global.is_received = 1;
}

void	signal_converter(void)
{
	if (g_global.get_len && ft_isdigit(g_global.rec_char))
	{
		if (!g_global.str_len_c)
			g_global.str_len_c = ft_calloc(1, 1);
		g_global.str_len_c
			= ft_charjoin(g_global.str_len_c, g_global.rec_char);
	}
	else if (g_global.str_len_c)
	{
		if (!g_global.cur_len)
		{
			g_global.int_len = ft_atoi(g_global.str_len_c);
			g_global.str_client = ft_calloc(g_global.int_len + 1, 1);
			g_global.get_len = 0;
		}
		g_global.str_client[g_global.cur_len++] = g_global.rec_char;
		if (g_global.cur_len >= g_global.int_len)
		{
			ft_printf("\033[0;32m%s\033[0m\n", g_global.str_client);
			string_reset();
		}
	}
	g_global.rec_char = 0;
	g_global.bits_received = 0;
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	context = NULL;
	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		if (info->si_pid > 0)
			g_global.client_pid = info->si_pid;
		g_global.rec_char <<= 1;
		if (signo == SIGUSR1)
			g_global.rec_char |= 1;
		g_global.bits_received++;
		if (g_global.bits_received == 8)
		{
			signal_converter();
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
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ft_send_message(msg_len, server_pid))
		ft_send_message(message, server_pid);
	g_global.is_received = 0;
	while (!g_global.is_received)
		pause();
	free(msg_len);
	exit(0);
}
