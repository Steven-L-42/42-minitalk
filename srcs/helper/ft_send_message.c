/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:26:27 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 10:59:48 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minitalk.h"

int	ft_send_message(char *message, int server_pid)
{
	int	i;
	int	bit;

	if (kill(server_pid, SIGUSR2) == -1)
		return (ft_printf("Server does not exist!"), 0);
	i = 0;
	while (message[i])
	{
		bit = 128;
		while (bit > 0)
		{
			if (message[i] & bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bit /= 2;
			usleep(200);
		}
		i++;
	}
	return (1);
}
