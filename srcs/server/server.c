/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:54:20 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 11:45:26 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minitalk.h"

static t_global	g_global = {0, 0, -1, 0, NULL, NULL, NULL, NULL, 0, 0, 1};

void	string_reset(void)
{
	free(g_global.str_server);
	free(g_global.str_len_s);
	g_global.str_server = NULL;
	g_global.str_len_s = NULL;
	g_global.cur_len = 0;
	g_global.int_len = 0;
	g_global.get_len = 1;
}

void	signal_converter(void)
{
	if (g_global.get_len && ft_isdigit(g_global.rec_char))
	{
		if (!g_global.str_len_s)
			g_global.str_len_s = ft_calloc(1, 1);
		g_global.str_len_s
			= ft_charjoin(g_global.str_len_s, g_global.rec_char);
	}
	else if (g_global.str_len_s)
	{
		if (!g_global.cur_len)
		{
			g_global.int_len = ft_atoi(g_global.str_len_s);
			g_global.str_server = ft_calloc(g_global.int_len + 1, 1);
			g_global.get_len = 0;
		}
		g_global.str_server[g_global.cur_len++] = g_global.rec_char;
		if (g_global.cur_len >= g_global.int_len)
		{
			ft_printf("%s\n", g_global.str_server);
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

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	ft_printf("\033[0;33mServer PID: %d\033[0m\n", server_pid);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(0);
}
